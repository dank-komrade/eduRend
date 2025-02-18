#include "Cube.h"

CubeModel::CubeModel(
	ID3D11Device* dxdevice,
	ID3D11DeviceContext* dxdevice_context)
	: Model(dxdevice, dxdevice_context)
{
	// Vertex and index arrays
	// Once their data is loaded to GPU buffers, they are not needed anymore
	std::vector<Vertex> vertices;
	std::vector<unsigned> indices;

	// Populate the vertex array with 24 vertices
	Vertex v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23;
	//1# - front
	v0.Pos = { -0.5f, -0.5f, 0.5f };
	v0.Normal = {  0  ,   0   , -1 };
	v0.TexCoord = { 0, 0 };

	v1.Pos = { 0.5f, -0.5f, 0.5f };
	v1.Normal = {    0 ,    0  , -1 };
	v1.TexCoord = { 0, 1 };

	v2.Pos = { 0.5f, 0.5f, 0.5f };
	v2.Normal = { 0 ,    0   , -1 };
	v2.TexCoord = { 1, 1 };

	v3.Pos = { -0.5f, 0.5f, 0.5f };
	v3.Normal = { 0  ,   0   , -1 };
	v3.TexCoord = { 1, 0 };



	//2# bottom
	v9.Pos = { -0.5f, -0.5f, 0.5f };
	v9.Normal = { 0    ,   -1   ,  0};
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
	v10.Normal = {   1 , 0     ,  0};
	v10.TexCoord = { 0, 1 };

	v12.Pos = { 0.5f, 0.5f, 0.5f };
	v12.Normal = {   1 , 0    , 0 };
	v12.TexCoord = { 1, 1 };

	v18.Pos = { 0.5f, -0.5f, -0.5f };
	v18.Normal = { 1  , 0      ,0 };
	v18.TexCoord = { 1, 1 };

	v20.Pos = { 0.5f, 0.5f, -0.5f };
	v20.Normal = { 1   , 0     , 0 };
	v20.TexCoord = { 0 , 0 };


	
	//4# - left
	v14.Pos = { -0.5f, 0.5f, 0.5f };
	v14.Normal = { -1    , 0    ,  0};
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
	v4.Normal = {  0  , 0     , 1 };
	v4.TexCoord = { 1 , 0 };

	v5.Pos = { 0.5f, -0.5f, -0.5f };
	v5.Normal = {   0  ,    0   , 1 };
	v5.TexCoord = { 1, 1 };

	v6.Pos = { 0.5f, 0.5f, -0.5f };
	v6.Normal = { 0   ,   0    , 1 };
	v6.TexCoord = { 0 , 1 };

	v7.Pos = { -0.5f, 0.5f, -0.5f };
	v7.Normal = {  0  ,   0 , 1 };
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
}


void CubeModel::Render()
{
	// Bind our vertex buffer
	const UINT32 stride = sizeof(Vertex); //  sizeof(float) * 8;
	const UINT32 offset = 0;
	dxdevice_context->IASetVertexBuffers(0, 1, &vertex_buffer, &stride, &offset);

	// Bind our index buffer
	dxdevice_context->IASetIndexBuffer(index_buffer, DXGI_FORMAT_R32_UINT, 0);

	// Make the drawcall
	dxdevice_context->DrawIndexed(nbr_indices, 0, 0);
}

