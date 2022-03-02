SamplerState texSampler : register(s0);
Texture2D texDiffuse : register(t0);

cbuffer LightcamBuffer : register(b0)
{
	float4 CameraPosition;
	float4 LightPosition;
};

cbuffer MaterialBuffer : register(b1)
{
	float4 Ka;
	float4 Kd; 
	float4 Ks; 
};

struct PSIn
{
	float4 Pos  : SV_Position;
	float3 Normal : NORMAL;
	float2 TexCoord : TEX;
	float3 PosWorld : POSITION;
};

//-----------------------------------------------------------------------------------------
// Pixel Shader
//-----------------------------------------------------------------------------------------

float4 PS_main(PSIn input) : SV_Target
{
	// Debug shading #1: map and return normal as a color, i.e. from [-1,1]->[0,1] per component
	// The 4:th component is opacity and should be = 1

	//return float4(input.Normal*0.5+0.5, 1);
	float3 L = normalize(LightPosition.xyz - input.PosWorld); 
    float3 N = input.Normal;
	float3 R = reflect(-L, N);
	float3 V = normalize(CameraPosition.xyz - input.PosWorld);
    return float4(Ka + (texDiffuse.Sample(texSampler, input.TexCoord) * max(dot(L ,N), 0)) + Ks* pow(max(dot(R, V), 0), 90));

	/*return texDiffuse.Sample(texSampler, input.TexCoord);*/

	// Debug shading #2: map and return texture coordinates as a color (blue = 0)
//	return float4(input.TexCoord, 0, 1);
}