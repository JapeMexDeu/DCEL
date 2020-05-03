
#include"DCEL.hpp"

#include<iostream>


using namespace std;

using namespace std;

int main()
{
	DCEL Mesh;
	cout<<"\nLets reserve space already, so we wont have any issues: \n";
	Mesh.getVer
	cout<<"Creation of a DCEL and addition of a vertices\n";
	
	Mesh.getVertices().reserve(10);
	Mesh.createVertex();
	Mesh.getVertex(0)->setData(0,0,0);
	Mesh.getVertices()[0].printVertex();
	Mesh.createVertex();
	Mesh.getVertex(1)->setData(1,1,1);
	Mesh.getVertices()[1].printVertex();
	
	cout<<"Size of vertices vector is: "<<Mesh.getVertices().size();
	cout<<"Size of halfedge vector is: "<<Mesh.getHalfEdges().size();
	
	Mesh.createEdge(Mesh.getVertex(0),Mesh.getVertex(1),nullptr,nullptr);
	cout<<"\nPrinting vertex info from origin of hes\n";
	Mesh.getHalfEdge(0)->getOriginVertex()->printVertex();
	Mesh.getHalfEdge(1)->getOriginVertex()->printVertex();
	
	cout<<"\nPrinting vertex info from twin of hes\n";
	Mesh.getHalfEdge(1)->getPairEdge()->getOriginVertex()->printVertex();
	cout<<"\nFor first one\n";
	Mesh.getHalfEdge(0)->getPairEdge()->getOriginVertex()->printVertex();
	return 0;
}