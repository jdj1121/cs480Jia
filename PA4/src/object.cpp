#include "object.h"

using namespace std;

Object::Object()
{  
  /*
    # Blender File for a Cube
    o Cube
    v 1.000000 -1.000000 -1.000000
    v 1.000000 -1.000000 1.000000
    v -1.000000 -1.000000 1.000000
    v -1.000000 -1.000000 -1.000000
    v 1.000000 1.000000 -0.999999
    v 0.999999 1.000000 1.000001
    v -1.000000 1.000000 1.000000
    v -1.000000 1.000000 -1.000000
    s off
    f 2 3 4
    f 8 7 6
    f 1 5 6
    f 2 6 7
    f 7 8 4
    f 1 4 8
    f 1 2 4
    f 5 8 6
    f 2 1 6
    f 3 2 7
    f 3 7 4
    f 5 1 8
  */

  if(loadOBJ("model/box.obj"))
  {
	  // The index works at a 0th index
	  for(unsigned int i = 0; i < Indices.size(); i++)
	  {
	    Indices[i] = Indices[i] - 1;
	  }

	  angle = 0.0f;

	  glGenBuffers(1, &VB);
	  glBindBuffer(GL_ARRAY_BUFFER, VB);
	  glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * Vertices.size(), &Vertices[0], GL_STATIC_DRAW);

	  glGenBuffers(1, &IB);
	  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IB);
	  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * Indices.size(), &Indices[0], GL_STATIC_DRAW);
  }

  else
  {
	cout<<"Error: OBJ file doesn't exist!"<<endl;
  }
}

Object::~Object()
{
  Vertices.clear();
  Indices.clear();
}

void Object::Update(unsigned int dt)
{
  angle += dt * M_PI/5000;

  model = glm::rotate( glm::mat4(1.0f), (angle), glm::vec3(0.0, 1.0, 0.0));  
}

glm::mat4 Object::GetModel()
{
  return model;
}

void Object::Render()
{
  glEnableVertexAttribArray(0);
  glEnableVertexAttribArray(1);

  glBindBuffer(GL_ARRAY_BUFFER, VB);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex,color));

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IB);

  glDrawElements(GL_TRIANGLES, Indices.size(), GL_UNSIGNED_INT, 0);

  glDisableVertexAttribArray(0);
  glDisableVertexAttribArray(1);
}

bool Object::loadOBJ(char * obj)
{
	ifstream fin(obj);

	if(fin.is_open())
	{
		char first;
		char ig[256];
		int in;
		//vector<Vertex> ver;
		//vector<int> index;

		first = fin.get();

		while (first != 'v' && first != 'f')
		{
			fin.getline (ig,256);
			first = fin.get();
		}

  		while (first == 'v'){
		Vertex tmp({0.0f,0.0f,0.0f},{RandomFloat(0.0f, 1.0f),RandomFloat(0.0f, 1.0f),RandomFloat(0.0f, 1.0f)});
  			first = fin.get(); 
  			if ( first == ' ')
  			{
		  		fin >> tmp.vertex.x;
				fin >> tmp.vertex.y;
				fin >> tmp.vertex.z;
				Vertices.push_back (tmp);
		  		fin.getline (ig,256);
	  		}
	  		if ( first == 'n')
	  		{
	  			fin.getline (ig,256);
	  		}
	  		first = fin.get(); 
  		}

		while (first != 'v' && first != 'f')
		{
			fin.getline (ig,256);
			first = fin.get();
		}

  		while (first == 'f'){
  			first = fin.get(); 
		  	fin >> in;
		  	Indices.push_back (in);
		  	fin.ignore(256,' ');
		  	fin >> in;
		  	Indices.push_back (in);
		  	fin.ignore(256,' ');
		  	fin >> in;
		  	Indices.push_back (in);

		  	fin.getline (ig,256);
	  		
	  		first = fin.get(); 
  		}

		fin.close();
		return true;
	}

	else
	{
		return false;
	}

}

float Object::RandomFloat(float a, float b) {
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}
