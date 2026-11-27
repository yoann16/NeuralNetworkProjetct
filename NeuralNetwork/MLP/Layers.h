#ifndef LAYERS_H
#define LAYERS_H
#pragma once

#include <cstddef>
#include <vector>
#include <map>
#include <utility>
#include <tuple>
#include <random>
#include <ranges>
#include <algorithm>

#include "MLP/Neuron.h"

namespace MLP::Neuron
{
	struct Neuron;
}

namespace MLP::Layers 
{
	class Matrice
	{
	private:
		//std::map<std::pair<MLP::Neuron::Neuron, MLP::Neuron::Neuron>, float> matrice_;
		std::vector <std::tuple<MLP::Neuron::Neuron, MLP::Neuron::Neuron, float>> matrice_;
		std::size_t sizePreviousLayer_;
		std::size_t sizeCurrentLayer_;
	public:
		Matrice(const std::vector<MLP::Neuron::Neuron>& neuronsPreviousLayer, const std::vector<MLP::Neuron::Neuron>& neuronsCurrentLayer)
			: sizePreviousLayer_(neuronsPreviousLayer.size())
			, sizeCurrentLayer_(neuronsCurrentLayer.size())
		{ 
			matrice_.reserve(sizePreviousLayer_ * sizeCurrentLayer_);

			std::random_device rd;
			std::mt19937 gen(rd());

			for (auto& neuronCurr : neuronsCurrentLayer)
			{
				for (auto& neuronPrev : neuronsPreviousLayer)
				{
					std::uniform_real_distribution<float> dist_real(0.0f, 10.0f);
					matrice_.emplace_back(std::tuple{ neuronPrev, neuronCurr, dist_real(gen)});
				}
			}
		}

		std::pair<std::size_t, std::size_t> findCurrentNeuronRange(const MLP::Neuron::Neuron& currentNeuron)
		{
			auto lastPosVector = matrice_.size() - 1;

		}

		float findConnectionWeight(const MLP::Neuron::Neuron& inputNeuron, const MLP::Neuron::Neuron& outputNeuron)
		{
			return 0.0f;
		}
	};

	struct Layer
	{
		std::vector<MLP::Neuron::Neuron> neurons;
		Matrice connectionWeights;
		Layer* prevLayer = nullptr;

		void activationLayer();
	};
}
#endif