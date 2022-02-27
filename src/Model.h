
//
//  Model.h
//
//  Carl Johan Gribel 2016, cjgribel@gmail.com
//

#pragma once
#ifndef MODEL_H
#define MODEL_H

#include "stdafx.h"
#include <vector>
#include "vec\vec.h"
#include "vec\mat.h"
#include "ShaderBuffers.h"
#include "Drawcall.h"
#include "OBJLoader.h"
#include "Texture.h"

using namespace linalg;

class Model
{
protected:
	// Pointers to the current device and device context
	ID3D11Device* const			dxdevice;
	ID3D11DeviceContext* const	dxdevice_context;

	// Pointers to the class' vertex & index arrays
	ID3D11Buffer* vertex_buffer = nullptr;
	ID3D11Buffer* index_buffer = nullptr;

    ID3D11Buffer* mtl_buffer = nullptr;
    struct MaterialBuffer
	{
		vec4f Ka;
		vec4f Kd;
		vec4f Ks;
	};

	Material mtl = Material();

	void InitMaterialBuffer();

	void UpdateMaterialBuffer(
		vec4f Ka, vec4f Kd, vec4f Ks);

public:

	Model(
		ID3D11Device* dxdevice, 
		ID3D11DeviceContext* dxdevice_context) 
		:	dxdevice(dxdevice),
			dxdevice_context(dxdevice_context)
	{
		mtl.Kd_texture_filename ="assets/textures/yroadcrossing.png";
	}

	//
	// Abstract render method: must be implemented by derived classes
	//
	virtual void Render() = 0;

	//
	// Destructor
	//
	virtual ~Model()
	{ 
		SAFE_RELEASE(vertex_buffer);
		SAFE_RELEASE(index_buffer);
		SAFE_RELEASE(mtl_buffer);
	}
};

class QuadModel : public Model
{
	unsigned nbr_indices = 0;
	

public:

	QuadModel(
		ID3D11Device* dx3ddevice,
		ID3D11DeviceContext* dx3ddevice_context);

	

	virtual void Render();

	~QuadModel() { }
};

class OBJModel : public Model
{
	// index ranges, representing drawcalls, within an index array
	struct IndexRange
	{
		unsigned int start;
		unsigned int size;
		unsigned ofs;
		int mtl_index;
	};

	std::vector<IndexRange> index_ranges;
	std::vector<Material> materials;

	void append_materials(const std::vector<Material>& mtl_vec)
	{
		materials.insert(materials.end(), mtl_vec.begin(), mtl_vec.end());
	}


public:

	OBJModel(
		const std::string& objfile,
		ID3D11Device* dxdevice,
		ID3D11DeviceContext* dxdevice_context);

	virtual void Render();

	~OBJModel();
};

#endif