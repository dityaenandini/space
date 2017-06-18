#ifndef CSE167_OBJObject_h
#define CSE167_OBJObject_h

#include <iostream>
#include <vector>
#include <string>
#include "Vector3.h"
#include "Drawable.h"
#include "Material.h"

class Face
{
	public:
		int vs[3];
		int ns[3];
		int ts[3];
};

class OBJObject : public Drawable
{
    
protected:
    //Helper functions
    std::vector<std::string>& split(const std::string&, char, std::vector<std::string>&);
    std::vector<std::string> split(const std::string&, char);
    
public:
	std::vector<Vector3*>* vertices;
	std::vector<Vector3*>* normals;
	std::vector<Vector3*>* texcoords;
	std::vector<Face*>* faces;

	int face_num;
    OBJObject(/*std::string*/);
    virtual ~OBJObject(void);
    
    virtual void draw(DrawData&);
	//virtual void myDraw(DrawData&, bool mode);
    virtual void update(UpdateData&);

	void parse(std::string&);

	void spin(float);
    
};

#endif
