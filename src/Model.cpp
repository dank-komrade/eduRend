//
//  Model.cpp
//
//  CJ Gribel 2016, cjgribel@gmail.com
//

#include "Model.h"

QuadModel::QuadModel(
	ID3D11Device* dxdevice,
	ID3D11DeviceContext* dxdevice_context)
	: Model(dxdevice, dxdevice_context)
{
	// Vertex and index arrays
	// Once their data is loaded to GPU buffers, they are not needed anymore
	std::vector<Vertex> vertices;
	std::vector<unsigned> indices;


	Vertex v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23;
	//1# - front
	v0.Pos = { -0.5f, -0.5f, 0.5f };
	v0.Normal = { 0  ,   0   , -1 };
	v0.TexCoord = { 0, 0 };

	v1.Pos = { 0.5f, -0.5f, 0.5f };
	v1.Normal = { 0 ,    0  , -1 };
	v1.TexCoord = { 0, 1 };

	v2.Pos = { 0.5f, 0.5f, 0.5f };
	v2.Normal = { 0 ,    0   , -1 };
	v2.TexCoord = { 1, 1 };

	v3.Pos = { -0.5f, 0.5f, 0.5f };
	v3.Normal = { 0  ,   0   , -1 };
	v3.TexCoord = { 1, 0 };



	//2# bottom
	v9.Pos = { -0.5f, -0.5f, 0.5f };
	v9.Normal = { 0    ,   -1   ,  0 };
	v9.TexCoord = { 0, 0 };

	v11.Pos = { 0.5f, -0.5f, 0.5f };
	v11.Normal = { 0    ,   -1   ,  0 };
	v11.TexCoord = { 0, 1 };

	v19.Pos = { 0.5f, -0.5f, -0.5f };
	v19.Normal = { 0    ,   -1   ,  0 };
	v19.TexCoord = { 1, 1 };

	v17.Pos = { -0.5f, -0.5f, -0.5f };
	v17.Normal = { 0    , -1    , 0 };
	v17.TexCoord = { 1 , 0 };



	//3# -right
	v10.Pos = { 0.5f, -0.5f, 0.5f };
	v10.Normal = { 1 , 0     ,  0 };
	v10.TexCoord = { 0, 1 };

	v12.Pos = { 0.5f, 0.5f, 0.5f };
	v12.Normal = { 1 , 0    , 0 };
	v12.TexCoord = { 1, 1 };

	v18.Pos = { 0.5f, -0.5f, -0.5f };
	v18.Normal = { 1  , 0      ,0 };
	v18.TexCoord = { 1, 1 };

	v20.Pos = { 0.5f, 0.5f, -0.5f };
	v20.Normal = { 1   , 0     , 0 };
	v20.TexCoord = { 0 , 0 };



	//4# - left
	v14.Pos = { -0.5f, 0.5f, 0.5f };
	v14.Normal = { -1    , 0    ,  0 };
	v14.TexCoord = { 1, 1 };

	v8.Pos = { -0.5, -0.5f, 0.5f };
	v8.Normal = { -1   , 0   ,  0 };
	v8.TexCoord = { 0, 0 };

	v16.Pos = { -0.5f, -0.5f, -0.5f };
	v16.Normal = { -1  , 0    , 0 };
	v16.TexCoord = { 1 , 0 };

	v22.Pos = { -0.5f, 0.5f, -0.5f };
	v22.Normal = { -1 , 0     ,  0 };
	v22.TexCoord = { 0, 1 };



	//5# top
	v15.Pos = { -0.5f, 0.5f, 0.5f };
	v15.Normal = { /*0.5f */ 0  ,  1   , 0 };
	v15.TexCoord = { 1, 0 };

	v13.Pos = { 0.5f, 0.5f, 0.5f };
	v13.Normal = { /*0.5f */  0 , 1      , 0 };
	v13.TexCoord = { 1, 1 };

	v21.Pos = { 0.5f, 0.5f, -0.5f };
	v21.Normal = { /*0.5f*/ 0  ,  1     ,  0 };
	v21.TexCoord = { 0 , 1 };

	v23.Pos = { -0.5f, 0.5f, -0.5f };
	v23.Normal = { /*0.5f*/  0  ,   1  , 0 };
	v23.TexCoord = { 0, 0 };



	//6# -back
	v4.Pos = { -0.5f, -0.5f, -0.5f };
	v4.Normal = { 0  , 0     , 1 };
	v4.TexCoord = { 1 , 0 };

	v5.Pos = { 0.5f, -0.5f, -0.5f };
	v5.Normal = { 0  ,    0   , 1 };
	v5.TexCoord = { 1, 1 };

	v6.Pos = { 0.5f, 0.5f, -0.5f };
	v6.Normal = { 0   ,   0    , 1 };
	v6.TexCoord = { 0 , 1 };

	v7.Pos = { -0.5f, 0.5f, -0.5f };
	v7.Normal = { 0  ,   0 , 1 };
	v7.TexCoord = { 0, 0 };



	vertices.push_back(v0);
	vertices.push_back(v1);
	vertices.push_back(v2);
	vertices.push_back(v3);
	vertices.push_back(v4);
	vertices.push_back(v5);
	vertices.push_back(v6);
	vertices.push_back(v7);
	vertices.push_back(v8);
	vertices.push_back(v9);
	vertices.push_back(v10);
	vertices.push_back(v11);
	vertices.push_back(v12);
	vertices.push_back(v13);
	vertices.push_back(v14);
	vertices.push_back(v15);
	vertices.push_back(v16);
	vertices.push_back(v17);
	vertices.push_back(v18);
	vertices.push_back(v19);
	vertices.push_back(v20);
	vertices.push_back(v21);
	vertices.push_back(v22);
	vertices.push_back(v23);


	// Populate the index array with 12 triangles
	// Triangle #1 - front 
	indices.push_back(0);
	indices.push_back(1);
	indices.push_back(3);
	// Triangle #2
	indices.push_back(1);
	indices.push_back(2);
	indices.push_back(3);
	//Triangle #3 - back 
	indices.push_back(7);
	indices.push_back(5);
	indices.push_back(4);
	//Triangle #4
	indices.push_back(7);
	indices.push_back(6);
	indices.push_back(5);
	//Triangle #5 - right
	indices.push_back(20);
	indices.push_back(12);
	indices.push_back(10);
	//Triangle #6
	indices.push_back(10);
	indices.push_back(18);
	indices.push_back(20);
	//Triangle #7 - left
	indices.push_back(16);
	indices.push_back(8);
	indices.push_back(14);
	//Triangle #8
	indices.push_back(14);
	indices.push_back(22);
	indices.push_back(16);
	//trinangle 9 -top
	indices.push_back(21);
	indices.push_back(23);
	indices.push_back(15);
	//Triangle #10
	indices.push_back(21);
	indices.push_back(15);
	indices.push_back(13);
	//Triangle #11 - bottom
	indices.push_back(17);
	indices.push_back(11);
	indices.push_back(9);
	//Triangle #12
	indices.push_back(11);
	indices.push_back(17);
	indices.push_back(19);

	// Vertex array descriptor
	D3D11_BUFFER_DESC vbufferDesc = { 0 };
	vbufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	vbufferDesc.CPUAccessFlags = 0;
	vbufferDesc.Usage = D3D11_USAGE_DEFAULT;
	vbufferDesc.MiscFlags = 0;
	vbufferDesc.ByteWidth = (UINT)(vertices.size() * sizeof(Vertex));
	// Data resource
	D3D11_SUBRESOURCE_DATA vdata;
	vdata.pSysMem = &vertices[0];
	// Create vertex buffer on device using descriptor & data
	const HRESULT vhr = dxdevice->CreateBuffer(&vbufferDesc, &vdata, &vertex_buffer);
	SETNAME(vertex_buffer, "VertexBuffer");

	//  Index array descriptor
	D3D11_BUFFER_DESC ibufferDesc = { 0 };
	ibufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	ibufferDesc.CPUAccessFlags = 0;
	ibufferDesc.Usage = D3D11_USAGE_DEFAULT;
	ibufferDesc.MiscFlags = 0;
	ibufferDesc.ByteWidth = (UINT)(indices.size() * sizeof(unsigned));
	// Data resource
	D3D11_SUBRESOURCE_DATA idata;
	idata.pSysMem = &indices[0];
	// Create index buffer on device using descriptor & data
	const HRESULT ihr = dxdevice->CreateBuffer(&ibufferDesc, &idata, &index_buffer);
	SETNAME(index_buffer, "IndexBuffer");

	nbr_indices = (unsigned int)indices.size();
	InitMaterialBuffer();


	HRESULT hr = LoadTextureFromFile(dxdevice, dxdevice_context, mtl.Kd_texture_filename.c_str(), &mtl.diffuse_texture);


}



void QuadModel::Render()
{
	// Bind our vertex buffer
	const UINT32 stride = sizeof(Vertex); //  sizeof(float) * 8;
	const UINT32 offset = 0;
	dxdevice_context->IASetVertexBuffers(0, 1, &vertex_buffer, &stride, &offset);

	// Bind our index buffer
	dxdevice_context->IASetIndexBuffer(index_buffer, DXGI_FORMAT_R32_UINT, 0);

	// Make the drawcall
	dxdevice_context->DrawIndexed(nbr_indices, 0, 0);

	dxdevice_context->PSSetConstantBuffers(1, 1, &mtl_buffer);
	dxdevice_context->PSSetShaderResources(
		0, // texture slot #
		1, // bind just one buffer
		&mtl.diffuse_texture.texture_SRV);

	vec4f Ka = { 0.1, 0.1, 0.1, 1 }, Kd = { 0, 0.5, 0, 1 }, Ks = { 1, 1, 1, 1 };
	UpdateMaterialBuffer(Ka, Kd, Ks);
}

void Model::InitMaterialBuffer() {
	D3D11_BUFFER_DESC MaterialBuffer_desc = { 0 };
	MaterialBuffer_desc.Usage = D3D11_USAGE_DYNAMIC;
	MaterialBuffer_desc.ByteWidth = sizeof(MaterialBuffer);
	MaterialBuffer_desc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	MaterialBuffer_desc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	MaterialBuffer_desc.MiscFlags = 0;
	MaterialBuffer_desc.StructureByteStride = 0;
	const HRESULT hr = dxdevice->CreateBuffer(&MaterialBuffer_desc, nullptr, &mtl_buffer);
}

void Model::UpdateMaterialBuffer(
	vec4f Ka, vec4f Kd, vec4f Ks)
{
	D3D11_MAPPED_SUBRESOURCE resource;
	dxdevice_context->Map(mtl_buffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &resource);
	MaterialBuffer* mtlBuffer_ = (MaterialBuffer*)resource.pData;
	mtlBuffer_->Ka = Ka;
	mtlBuffer_->Kd = Kd;
	mtlBuffer_->Ks = Ks;
	dxdevice_context->Unmap(mtl_buffer, 0);
}

OBJModel::OBJModel(
	const std::string& objfile,
	ID3D11Device* dxdevice,
	ID3D11DeviceContext* dxdevice_context)
	: Model(dxdevice, dxdevice_context)
{
	// Load the OBJ
	OBJLoader* mesh = new OBJLoader();
	mesh->Load(objfile);

	// Load and organize indices in ranges per drawcall (material)

	std::vector<unsigned> indices;
	unsigned int i_ofs = 0;

	for (auto& dc : mesh->drawcalls)
	{
		// Append the drawcall indices
		for (auto& tri : dc.tris)
		{
			indices.insert(indices.end(), tri.vi, tri.vi + 3);

			auto& v0 = mesh->vertices[tri.vi[0]];
			auto& v1 = mesh->vertices[tri.vi[1]];
			auto& v2 = mesh->vertices[tri.vi[2]];

			vec3f D = v1.Pos - v0.Pos;
			vec3f E = v2.Pos - v0.Pos;
			vec2f F = v1.TexCoord - v0.TexCoord;
			vec2f G = v2.TexCoord - v0.TexCoord;

			float detInverse = 1.0f / (F.x * G.y - F.y * G.x);

			vec3f T, B;

			T.x = (G.y * D.x - F.y * E.x) * detInverse;
			T.y = (G.y * D.y - F.y * E.y) * detInverse;
			T.z = (G.y * D.z - F.y * E.z) * detInverse;

			B.x = (-G.x * D.x + F.x * E.x) * detInverse;
			B.y = (-G.x * D.y + F.x * E.y) * detInverse;
			B.z = (-G.x * D.z + F.x * E.z) * detInverse;

			T = normalize(T);
			B = normalize(B);

			v0.Tangent = v1.Tangent = v2.Tangent = T;
			v0.Binormal = v1.Binormal = v2.Binormal = B;


		}

		// Create a range
		unsigned int i_size = (unsigned int)dc.tris.size() * 3;
		int mtl_index = dc.mtl_index > -1 ? dc.mtl_index : -1;
		index_ranges.push_back({ i_ofs, i_size, 0, mtl_index });

		i_ofs = (unsigned int)indices.size();
	}



	// Vertex array descriptor
	D3D11_BUFFER_DESC vbufferDesc = { 0 };
	vbufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	vbufferDesc.CPUAccessFlags = 0;
	vbufferDesc.Usage = D3D11_USAGE_DEFAULT;
	vbufferDesc.MiscFlags = 0;
	vbufferDesc.ByteWidth = (UINT)(mesh->vertices.size() * sizeof(Vertex));
	// Data resource
	D3D11_SUBRESOURCE_DATA vdata;
	vdata.pSysMem = &(mesh->vertices)[0];
	// Create vertex buffer on device using descriptor & data
	HRESULT vhr = dxdevice->CreateBuffer(&vbufferDesc, &vdata, &vertex_buffer);
	SETNAME(vertex_buffer, "VertexBuffer");

	// Index array descriptor
	D3D11_BUFFER_DESC ibufferDesc = { 0 };
	ibufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	ibufferDesc.CPUAccessFlags = 0;
	ibufferDesc.Usage = D3D11_USAGE_DEFAULT;
	ibufferDesc.MiscFlags = 0;
	ibufferDesc.ByteWidth = (UINT)(indices.size() * sizeof(unsigned));
	// Data resource
	D3D11_SUBRESOURCE_DATA idata;
	idata.pSysMem = &indices[0];
	// Create index buffer on device using descriptor & data
	HRESULT ihr = dxdevice->CreateBuffer(&ibufferDesc, &idata, &index_buffer);
	SETNAME(index_buffer, "IndexBuffer");

	// Copy materials from mesh
	append_materials(mesh->materials);

	// Go through materials and load textures (if any) to device
	std::cout << "Loading textures..." << std::endl;
	for (auto& mtl : materials)
	{
		HRESULT hr;

		// Load Diffuse texture
		//
		if (mtl.Kd_texture_filename.size()) {

			hr = LoadTextureFromFile(
				dxdevice,
				dxdevice_context,
				mtl.Kd_texture_filename.c_str(),
				&mtl.diffuse_texture);
			std::cout << "\t" << mtl.Kd_texture_filename
				<< (SUCCEEDED(hr) ? " - OK" : "- FAILED") << std::endl;
		}

		// + other texture types here - see Material class
		// ...



	}
	std::cout << "Done." << std::endl;

	SAFE_DELETE(mesh);
}


void OBJModel::Render()
{
	// Bind vertex buffer
	const UINT32 stride = sizeof(Vertex);
	const UINT32 offset = 0;
	dxdevice_context->IASetVertexBuffers(0, 1, &vertex_buffer, &stride, &offset);

	// Bind index buffer
	dxdevice_context->IASetIndexBuffer(index_buffer, DXGI_FORMAT_R32_UINT, 0);

	// Iterate drawcalls
	for (auto& irange : index_ranges)
	{
		// Fetch material
		const Material& mtl = materials[irange.mtl_index];

		// Bind diffuse texture to slot t0 of the PS
		dxdevice_context->PSSetShaderResources(0, 1, &mtl.diffuse_texture.texture_SRV);
		// + bind other textures here, e.g. a normal map, to appropriate slots

		// Make the drawcall
		dxdevice_context->DrawIndexed(irange.size, irange.start, 0);
	}
}

OBJModel::~OBJModel()
{
	for (auto& material : materials)
	{
		SAFE_RELEASE(material.diffuse_texture.texture_SRV);

		// Release other used textures ...
	}
}