#ifndef FACE_H
#define FACE_H

class HalfEdge;

class Face
{
    private:
        HalfEdge* borderingHalfEdge;//halfedge to the left
        
    public:
        Face():borderingHalfEdge(nullptr)
        {
            
        }
        void setBorderingHalfEdge(HalfEdge* border)
        {
            this->borderingHalfEdge=border;
        }
        HalfEdge* getBorderingHalfEdge()
        {
            return this->borderingHalfEdge;
        }

};

#endif