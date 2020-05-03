#ifndef VERTEX_H
#define VERTEX_H
class HalfEdge;
#include<iostream>
using std::cout;
//#include"HalfEdge.h"
//the first vertex has id 0 and the last vertex.size-1
class Vertex
{
	public:
		Vertex():incidentEdgePtr(nullptr){};//=default;
		Vertex(double x_, double y_, double z_):x(x_),y(y_),z(z_),incidentEdgePtr(nullptr){}
		
		void printVertex()
		{
			cout<<"<"<<x<<","<<y<<","<<z<<">";
		}
		//Setters and getters
		double getX(){ return x;}
		double getY(){ return y;}
		double getZ(){ return z;}
		HalfEdge* getIncidentEdge()
		{
			return this->incidentEdgePtr;
		}

		void setX(double x_){ x=x_;}
		void setY(double y_){ y=y_;}
		void setZ(double z_){ z=z_;}
		void setData(double x_,double y_,double z_)
		{
			this->x=x_;
			this->y=y_;
			this->z=z_;
		}
		void setIncidentEdge(HalfEdge* HEptr)
		{
			incidentEdgePtr=HEptr;
		}


	private:
	
		double x,y,z;
		HalfEdge* incidentEdgePtr;/**<Pointer to any halfedge originating on this vertex*/
};
#endif