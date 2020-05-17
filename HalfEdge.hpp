#ifndef HALFEDGE_H
#define HALFEDGE_H

class Vertex;
class Face;

class HalfEdge
{
    private:
        HalfEdge* nextEdge;
        HalfEdge* previousEdge;
        HalfEdge* pairEdge;

        Vertex* originVertex;

        Face* leftFace;
    public:
		//HalfEdge()=default;
         HalfEdge( ):nextEdge(nullptr),previousEdge(nullptr),pairEdge(nullptr),originVertex(nullptr),leftFace(nullptr)
		{
			//left empty
		};
        //setters and getters
        void setNextEdge(HalfEdge* edge)
		{ 
			this->nextEdge = edge;
			edge->nextEdge = this;
		}
		
        void setPreviousEdge(HalfEdge* edge)
		{
			this->previousEdge = edge;
			edge->previousEdge = this;
		}

		
        void setPairEdge(HalfEdge* edge)
		{ 
			this->pairEdge = edge;
			edge->pairEdge=this;

		}
		
        void setOriginVertex(Vertex* vertex){ this->originVertex=vertex;};
        void setLeftFace(Face* face)
		{ 
			leftFace=face;
		}
		
		HalfEdge* getNextEdge(){return this->nextEdge;};
		HalfEdge* getPreviousEdge(){return this->previousEdge;};
		HalfEdge* getPairEdge(){return this->pairEdge;};
		
		Vertex* getOriginVertex(){return this->originVertex;};
		
		Face* getLeftFace(){return this->leftFace;};

		//utility functio, should be deleted
		void printEdge()
		{
			cout << "From ";
			this->originVertex->printVertex();
			cout << " to ";
			this->pairEdge->getOriginVertex()->printVertex();
			
		}
  
};

#endif