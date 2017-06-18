#ifndef CSE167_Background_h
#define CSE167_Background_h

#include "Drawable.h"

class Background : public Drawable
{

public:

	float size;

	Background(float);
	virtual ~Background(void);
	void draw_bg(DrawData& data);	
	virtual void update(UpdateData&);
};

#endif

