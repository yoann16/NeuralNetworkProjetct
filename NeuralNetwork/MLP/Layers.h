#ifndef LAYERS_H
#define LAYERS_H
#pragma once

#include <cstddef>
#include <vector>
#include <print>
#include "Utility/Utility.h"
#include "MLP/Neuron.h"

namespace MLP::Layers 
{
	struct Matrice
	{

	};

	struct Layer
	{
		std::vector<MLP::Neuron::Neuron> neurons;
		std::size_t size = neurons.size();
		Matrice connectionWeights;
		Layer* prevLayer = nullptr;

		void activationLayer()
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
					neuronIndex.activation += prevLayerNeuronIndex.activation * connectionWeights;
				}

				neuronIndex.activation = sigmoid(neuronIndex.activation + neuronIndex.bias);
			}
		}
	};
}
#endif