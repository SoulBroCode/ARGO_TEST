#ifndef GRAPHARC_H
#define GRAPHARC_H
#include <iostream>




class GraphArc {
private:

	//GraphNode* m_pNode;

    float m_weight;

public:

	GraphArc() {

	}

	
    // Accessor functions
	
    void setWeight(float weight) {
       m_weight = weight;
    }
    
};

#endif
