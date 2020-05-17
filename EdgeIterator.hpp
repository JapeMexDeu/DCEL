#include"Vertex.h"
#include"Face.h"
#include"HalfEdge.hpp"
//No faces taken into account yet
class EdgeIterator
{
	public:
		EdgeIterator(Vertex* vertex)
		{
			this->restartVertex(vertex);
		}
		
		void restart()
		{
			this->nextEdge=this->beginEdge;
		}
		bool hasNextEdge()
		{
			return nextEdge!=nullptr;
		}
		HalfEdge* getNextHalfEdge( )
		{
			//temporary store the next  edge pointer value
			HalfEdge* temporaryNext=this->nextEdge;
			//if we have an actual next value, if the vertex is not unused
			if(nextEdge)//if next edge != nullptr
			{
				HalfEdge* pairEdge=this->nextEdge->getPairEdge();
				this->nextEdge=pairEdge->getNextEdge();
			}
			//if we are back to initial halfedge
			if(nextEdge==beginEdge)
			{
				this->nextEdge=nullptr; 
			}
			return temporaryNext;
		}
		
		
		void restartVertex(Vertex* vertex)
		{
			beginEdge=vertex->getIncidentEdge();
			restart();
		}
	private:
		HalfEdge* beginEdge;
		HalfEdge* nextEdge;
};