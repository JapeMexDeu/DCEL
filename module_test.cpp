#include"DCEL.hpp"
#include<iostream>

using namespace std;
/*Hard code a mesh for testing*/
void codeMesh(DCEL* Mesh)
{
	Mesh->reserveSpace(10, 10, 10);
	Mesh->createVertex(0, 0, 0);
	Mesh->createVertex(1, 0, 0);
	Mesh->createVertex(0, 1, 0);
	Mesh->createVertex(-1, 0, 0);
	Mesh->createVertex(0, -1, 0);

	Mesh->createEdge(Mesh->getVertex(0), Mesh->getVertex(1), nullptr, nullptr);
	Mesh->createEdge(Mesh->getVertex(0), Mesh->getVertex(2), nullptr, nullptr);
	Mesh->createEdge(Mesh->getVertex(0), Mesh->getVertex(3), nullptr, nullptr);
	Mesh->createEdge(Mesh->getVertex(0), Mesh->getVertex(4), nullptr, nullptr);

	Mesh->getVertex(0)->setIncidentEdge(Mesh->getHalfEdge(0));
	Mesh->getVertex(1)->setIncidentEdge(Mesh->getHalfEdge(1));
	Mesh->getVertex(2)->setIncidentEdge(Mesh->getHalfEdge(3));
	Mesh->getVertex(3)->setIncidentEdge(Mesh->getHalfEdge(5));
	Mesh->getVertex(4)->setIncidentEdge(Mesh->getHalfEdge(7));

}
int main()
{
	DCEL Mesh;
	codeMesh(&Mesh);

	Vertex* v1 = Mesh.getVertex(0);
	Vertex* v2 = Mesh.getVertex(3);
	HalfEdge* found = Mesh.getHalfEdge(v1, v2);
	//HalfEdge* found = Mesh.getHalfEdge(Mesh.getVertex(0), Mesh.getVertex(3));
	if (found != nullptr)
	{
		cout << "\n";
		found->printEdge();
		cout << "\n";
	}
	return 0;
}