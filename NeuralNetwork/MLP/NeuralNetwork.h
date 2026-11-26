#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H
#pragma once

#include <vector>


namespace MLP::Layers
{
	struct Layer;
}

namespace MLP::NeuralNetwork 
{
	class NeuralNetwork
	{
	private:
		std::vector<MLP::Layers::Layer> graphLayer_;
	public:
		NeuralNetwork()
		{

		}
	};
}
#endif