
cbuffer TransformationBuffer : register(b0)
{
	matrix ModelToWorldMatrix;
	matrix WorldToViewMatrix;
	matrix ProjectionMatrix;
};

struct VSIn
{
	float3 Pos : POSITION;
	float3 Normal : NORMAL;
	float3 Tangent : TANGENT;
	float3 Binormal : BINORMAL;
	float2 TexCoord : TEX;
};

struct PSIn
{
	float4 Pos  : SV_Position;
	float3 Normal : NORMAL;
	float2 TexCoord : TEX;
	float3 PosWorld : POSITION;
	float3 Tangent : TANGENT;
	float3 Binormal : BINORMAL;
};

//-----------------------------------------------------------------------------------------
// Vertex Shader
//-----------------------------------------------------------------------------------------

PSIn VS_main(VSIn input)
{
	PSIn output = (PSIn)0;

	// Model->View transformation
	matrix MV = mul(WorldToViewMatrix, ModelToWorldMatrix);

	// Model->View->Projection (clip space) transformation
	// SV_Position expects the output position to be in clip space
	matrix MVP = mul(ProjectionMatrix, MV);

	// Perform transformations and send to output
	output.Pos = mul(MVP, float4(input.Pos, 1));
	output.Normal = normalize(mul(ModelToWorldMatrix, float4(input.Normal, 0)).xyz);

	output.Tangent = normalize(mul(ModelToWorldMatrix, float4(input.Tangent, 0)).xyz);

	output.Binormal = normalize(mul(ModelToWorldMatrix, float4(input.Binormal, 0)).xyz);

	float texScale = 1;
	output.TexCoord = input.TexCoord * texScale;
	output.PosWorld = mul(ModelToWorldMatrix, float4(input.Pos, 1)).xyz;
	return output;
}