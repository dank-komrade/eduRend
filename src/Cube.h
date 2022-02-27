#pragma once
#include "stdafx.h"
#include <vector>
#include "vec\vec.h"
#include "vec\mat.h"
#include "Model.h"
using namespace linalg;
//
//class Cube : public Model
//{
//protected:
//	// Pointers to the current device and device context
//	ID3D11Device* const			dxdevice;
//	ID3D11DeviceContext* const	dxdevice_context;
//
//	// Pointers to the class' vertex & index arrays
//	ID3D11Buffer* vertex_buffer = nullptr;
//	ID3D11Buffer* index_buffer = nullptr;
//
//public:
//
//	Cube(
//		ID3D11Device* dxdevice,
//		ID3D11DeviceContext* dxdevice_context)
//		: dxdevice(dxdevice),
//		dxdevice_context(dxdevice_context)
//	{ }
//
//	//
//	// Abstract render method: must be implemented by derived classes
//	//
//	 void Render() override;
//
//	//
//	// Destructor
//	//
//	virtual ~Cube()
//	{
//		SAFE_RELEASE(vertex_buffer);
//		SAFE_RELEASE(index_buffer);
//	}
//};
class CubeModel : public Model
{
	unsigned nbr_indices = 0;

public:

	CubeModel(
		ID3D11Device* dx3ddevice,
		ID3D11DeviceContext* dx3ddevice_context);

	 void Render() override;

	~CubeModel() { }
};
