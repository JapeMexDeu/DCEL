#ifndef DCEL_H
#define DCEL_H

#include<vector>
#include "Vertex.h"
#include "HalfEdge.hpp"
#include "Face.h"
#include "EdgeIterator.hpp"

class DCEL
{
    private:
        //These 3 could be Lists instead of Vectors...but we'll see
        std::vector<Vertex> vertices;
        std::vector<Face> faces;
        std::vector<HalfEdge> halfedges;

    public:
		//Vertex manipulation
		size_t createVertex();
		Vertex* createGetVertex();
        size_t createVertex(double x, double y, double z);
		
		void reserveSpace(size_t vertices, size_t edges, size_t faces);

		Vertex* getVertex(size_t vertex_id);
		//****End vertex manipulation
		
		//HalfEdge manipulation
		//Creates twin half edges
		size_t createEdge(Vertex* origin, Vertex* pairOrigin, Face* incidentFace,Face* pairIncidentFace);
		HalfEdge* getHalfEdge(size_t he_id);
		//Find half edge using the 2 vertices
		HalfEdge* getHalfEdge(Vertex* v1,Vertex* v2);
		//*****End HalfEdge manipulation
		
		//Face manipulation
		size_t createFace(HalfEdge* incidentHalfEdge);
		size_t createTriangularFace(size_t vId1,size_t vId2,size_t vId3);
		//****End Face manipulation
		
		//Vector access functions
		std::vector<Vertex>& getVertices();
		std::vector<Face>& getFaces();
		std::vector<HalfEdge>& getHalfEdges();
		//****End
};
#endif