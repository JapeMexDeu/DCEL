#include"DCEL.hpp"
Vertex* DCEL::createGetVertex()
{
	this->vertices.push_back(Vertex());
	return &this->vertices.back();
}
size_t DCEL::createVertex()
{
	this->vertices.push_back(Vertex());
	return this->vertices.size()-1;
}
size_t DCEL::createVertex(double x, double y, double z)
{
	this->vertices.push_back(Vertex(x,y,z));
	return this->vertices.size()-1;
}
Vertex* DCEL::getVertex(size_t vertex_id)
{
	return &this->vertices[vertex_id];
}

size_t DCEL::createEdge(Vertex* origin,Vertex* pairOrigin,Face* incidentFace,Face* incidentPairFace)
{
	/*Heres the deal, to use push_back you have already have used reserve(), for enough space as necessary, else the
	  memory being pointed by the pointer is corrupted. If, you have not used */
	size_t halfedgeid=this->halfedges.size();
	this->halfedges.push_back(HalfEdge());
	//first pointer
	HalfEdge* e1=&this->halfedges[halfedgeid];
	e1->setOriginVertex(origin);
	e1->setLeftFace(incidentFace);

	this->halfedges.push_back(HalfEdge());
	//second pointer
	HalfEdge* e2=&(this->halfedges[halfedgeid+1]);
	e2->setOriginVertex(pairOrigin);
	e2->setLeftFace(incidentPairFace);
	e2->getOriginVertex()->printVertex();
	
	//set pairs
	e1->setPairEdge(e2);
	
	cout<<"\nInside create edge, assigned twins with pointers, print vertex from edge 1\n";
	e2->getPairEdge()->getOriginVertex()->printVertex();
	cout<<"\nInside create edge, assigned twins with pointers, print vertex from edge 0\n";
	e1->getPairEdge()->getOriginVertex()->printVertex();
	
	//halfedges[halfedge_id].setPairEdge(&halfedges[halfedge_id+1]);
	return halfedgeid;
}

size_t DCEL::createFace(HalfEdge* incidentHalfEdge)
{
	size_t face_id=this->faces.size();
	this->faces.push_back(Face());
	Face* face=&this->faces[face_id];
	face->setBorderingHalfEdge(incidentHalfEdge);
	
	return face_id;
}

HalfEdge* DCEL::getHalfEdge(Vertex* v1,Vertex* v2)
{
	EdgeIterator iter(v1);
	//we look for the halfedge that has v2 as origin
	while(iter.hasNextEdge())//2 things can happen, the v1 and v2 dont form and edge, or the vertex is unused
	{
		HalfEdge* edge=iter.getNextHalfEdge();
		if(edge->getPairEdge()->getOriginVertex()==v2)
		{
			return edge;
		}
	}
	return nullptr;
}
HalfEdge* DCEL::getHalfEdge(size_t id)
{
	return &this->halfedges[id];
}
size_t DCEL::createTriangularFace(size_t vId1,size_t vId2,size_t vId3)
{
	Vertex* v1=getVertex(vId1);
	Vertex* v2=getVertex(vId2);
	Vertex* v3=getVertex(vId3);
	
	
	return 0;
}

//Vector access functions

std::vector<Vertex>& DCEL::getVertices()
{
	return this->vertices;
}
std::vector<Face>& DCEL::getFaces()
{
	return this->faces;
}
std::vector<HalfEdge>& DCEL::getHalfEdges()
{
	return this->halfedges;
}
//*****End