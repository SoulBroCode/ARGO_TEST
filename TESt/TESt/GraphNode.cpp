#include "GraphNode.h"
#include "GraphArc.h"
#include "stdafx.h"
GraphNode::GraphNode() :
	m_prevNode(0),
	m_hCost(-1),
	m_gCost(-1),
	m_arcList(std::vector<GraphArc>())
{

	
	/*
	m_shape = sf::CircleShape(RADIUS);
	m_shape.setOrigin(RADIUS, RADIUS);


	m_nameTxt = sf::Text("", font, 15);
	m_nameTxt.setOrigin(4, 8);
	m_hCostTxt = sf::Text("H(n)= ?", font, 11);
	m_hCostTxt.setOrigin(7, 7);
	m_gCostTxt = sf::Text("G(n)= ?", font, 11);
	m_gCostTxt.setOrigin(7, 7);*/
}



GraphArc* GraphNode::getArc(GraphNode* pNode) {

	std::vector<GraphArc>::iterator iter = m_arcList.begin();
	std::vector<GraphArc>::iterator endIter = m_arcList.end();
	GraphArc* pArc = 0;

	/**/
	// find the arc that matches the node
	for (; iter != endIter && pArc == 0; ++iter) {
		if ((*iter).node() == pNode) {
			pArc = &((*iter));
		}
	}

	// returns null if not found
	return pArc;
}


void  GraphNode::reset() {
	m_marked = false;
	m_prevNode = 0;
	//m_shape.setFillColor(sf::Color::Blue);
	m_hCost = -1;
	m_gCost = -1;

	//m_hCostTxt.setString("H(n)= ?");
	//m_gCostTxt.setString("G(n)= ?");
}


void GraphNode::addArc(GraphNode* pNode, float weight) {
	// Create a new arc.
	GraphArc a;
	a.setNode(pNode);
	a.setWeight(weight);
	//a.setLine(m_position, pNode->getPosition());
	// Add it to the arc list.
	m_arcList.push_back(a);
}


// ----------------------------------------------------------------
//  Name:           removeArc
//  Description:    This finds an arc from this node to input node 
//                  and removes it.
//  Arguments:      None.
//  Return Value:   None.
// ----------------------------------------------------------------

void GraphNode::removeArc(GraphNode* pNode) {
	vector<GraphArc>::iterator iter = m_arcList.begin();
	vector<GraphArc>::iterator endIter = m_arcList.end();

	int size = m_arcList.size();
	// find the arc that matches the node
	for (; iter != endIter && m_arcList.size() == size;
		++iter) {
		GraphNode* node = (*iter).node();
		/*
		if (node == pNode) {
		m_arcList.remove( (*iter) );
		}          */

	}
}


