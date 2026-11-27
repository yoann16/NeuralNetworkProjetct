#include "MLP/Layers.h"

#include <print>

#include "Utility/Utility.h"


namespace MLP::Layers
{
	void Layer::activationLayer()
	{
		if (prevLayer == nullptr)
		{
			std::println("The layer has no preceding layer");
			return;
		}

		for (auto& neuronIndex : neurons)
		{
			for (auto& prevLayerNeuronIndex : prevLayer->neurons)
			{
				neuronIndex.activation += prevLayerNeuronIndex.activation
					* connectionWeights.findConnectionWeight(prevLayerNeuronIndex, neuronIndex);
			}

			neuronIndex.activation = sigmoid(neuronIndex.activation + neuronIndex.bias);
		}
	}
}
