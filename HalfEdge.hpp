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
		//attempt to have copy constructor
/* 		HalfEdge(const HalfEdge& hedge)
		{
			this->nextEdge=hedge.nextEdge;
			this->previousEdge=hedge.previousEdge;
			this->pairEdge=hedge.pairEdge;
			this->originVertex=hedge.originVertex;
			this->leftFace=hedge.leftFace;
		}
		//attempt at assignment operator
		HalfEdge& operator=(const HalfEdge& hedge)
		{
			//check self assignment
			//do copy
			this->nextEdge=hedge.nextEdge;
			this->previousEdge=hedge.previousEdge;
			this->pairEdge=hedge.pairEdge;
			this->originVertex=hedge.originVertex;
			this->leftFace=hedge.leftFace;
			
			return *this;
		} */
        //setters and getters
        void setNextEdge(HalfEdge* edge)
		{ 
			nextEdge=edge;
		}
		
        void setPreviousEdge(HalfEdge* edge)
		{
			previousEdge=edge;
		}

		
        void setPairEdge(HalfEdge* edge)
		{ 
			this->pairEdge = edge;
			
			/* cout<<"\n\nFrom setPairEdge";
			if(this->pairEdge==nullptr)
			{
				cout<<"\nIs nullptr\n";
			}
			else 
			{
				cout<<"\nIs not nullptr\n";
				this->pairEdge->getOriginVertex()->printVertex();
				cout<<"\n";
			} */
				
			edge->pairEdge=this;

		}
		
        void setOriginVertex(Vertex* vertex){ this->originVertex=vertex;};
        void setLeftFace(Face* face){ leftFace=face;};
		
		HalfEdge* getNextEdge(){return this->nextEdge;};
		HalfEdge* getPreviousEdge(){return this->previousEdge;};
		HalfEdge* getPairEdge(){return this->pairEdge;};
		
		Vertex* getOriginVertex(){return this->originVertex;};
		
		Face* getLeftFace(){return this->leftFace;};

  
};

#endif