#include "GLee.h"
#include <Windows.h>

#include "OBJObject.h"
#ifdef __APPLE__
    #include <GLUT/glut.h>
#else
    #include <GL/glut.h>
#endif

#include "Window.h"
#include "math.h"
#include <sstream>
#include <fstream>
#include <string.h>
using namespace std;

#define deleteVector(__vect__) do {\
                                   iter = __vect__->begin();\
                                   end = __vect__->end();\
                                   while(iter != end) delete (*(iter++));\
                                   delete __vect__;\
                               } while(false)


OBJObject::OBJObject(/*std::string filename*/) : Drawable()
{
    this->vertices = new std::vector<Vector3*>();
    this->normals = new std::vector<Vector3*>();
    this->texcoords = new std::vector<Vector3*>();
    this->faces = new std::vector<Face*>();
}

OBJObject::~OBJObject()
{
    //Delete any dynamically allocated memory/objects here
    std::vector<Vector3*>::iterator iter;
    std::vector<Vector3*>::iterator end;
    
    deleteVector(vertices);
    deleteVector(normals);
    deleteVector(texcoords);
    
    delete faces;
}

void OBJObject::draw(DrawData& data)
{
    material.apply();
    
    glMatrixMode(GL_MODELVIEW);
    
    glPushMatrix();
    glMultMatrixf(toWorld.ptr());
	//glLoadMatrixf(toWorld.ptr());
    
    glBegin(GL_TRIANGLES);

	Face* face;
	
	for (int i = 0; i < face_num; i++)
	{
		face = faces->at(i);

		for (int j = 0; j < 3; j++)
		{
			//Set normals
			Vector3 normal = *normals->at(face->ns[j] - 1);
			float xn = normal[2];
			float yn = normal[1];
			float zn = normal[0];
			glNormal3f(xn, yn, zn);
			
			//Set vectors
			Vector3 vertex = *vertices->at(face->vs[j] - 1);
			float xv = vertex[2];
			float yv = vertex[1];
			float zv = vertex[0];
			glVertex3f(xv, yv, zv);
		}
	}
    
    glEnd();
    
    glPopMatrix();
}

void OBJObject::update(UpdateData& data)
{
    //
}

void OBJObject::parse(std::string& filename)
{
    std::ifstream infile(filename);
    std::string line;
    std::vector<std::string> tokens;
    std::string token;
	std::vector<std::string> faceVals;
    
    int lineNum = 0;
    
    
    std::cout << "Starting parse..." << std::endl;
    
    //While all your lines are belong to us
    while (std::getline(infile, line))
    {
        //Progress
        if(++lineNum % 10000 == 0)
            std::cout << "At line " << lineNum << std::endl;

		if (line.empty())
			continue;
        
        //Split a line into tokens by delimiting it on spaces
        //"Er Mah Gerd" becomes ["Er", "Mah", "Gerd"]
        tokens.clear();
        tokens = split(line, ' ', tokens);
        
        //If first token is a v then it gots to be a vertex
        if(tokens.at(0).compare("v") == 0)
        {
            //Parse the vertex line
            float x = std::stof(tokens.at(1));
            float y = std::stof(tokens.at(2));
            float z = std::stof(tokens.at(3));
			vertices->push_back(new Vector3(x, y, z));
        }

        else if(tokens.at(0).compare("vn") == 0)
        {
            //Parse the normal line
			float x = std::stof(tokens.at(1));
			float y = std::stof(tokens.at(2));
			float z = std::stof(tokens.at(3));
			normals->push_back(new Vector3(x, y, z));
        }

        else if(tokens.at(0).compare("f") == 0)
        {
            Face* face = new Face();

			//Parse the face line
			for (int i = 1; i < 4; i++)
			{
				int j = i - 1;

				faceVals = split(tokens.at(i), '/', faceVals);
				face->vs[j] = stoi(faceVals.at(0));
				face->ns[j] = stoi(faceVals.at(2));
				//face.ts[j] = stoi(faceVals.at(1));
				faceVals.clear();
			}

			faces->push_back(face);
			face_num++;
        }

		else if (tokens.at(0).compare("vt") == 0)
		{
			//Parse the textures

			//Parse as appropriate
			//There are more line types than just the above listed
			//See the Wavefront Object format specification for details
		}
    }
    
    std::cout << "Done parsing." << std::endl;
}

//Split functions from the interwebs
//http://stackoverflow.com/questions/236129/split-a-string-in-c
std::vector<std::string>& OBJObject::split(const std::string &s, char delim, std::vector<std::string> &elems)
{
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim))
    {
        elems.push_back(item);
    }
    return elems;
}

std::vector<std::string> OBJObject::split(const std::string &s, char delim)
{
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}

void OBJObject::spin(float radians)
{
	Matrix4 rotation;
	rotation.makeRotateY(radians);

	toWorld = toWorld * rotation;
}
