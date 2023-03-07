
struct VS_OUTPUT
{
    float4  vPosition : POSITION;
    float4  vDiffuse : COLOR;
};

static float2 positions[3] = {
    float2(0.0, -0.5),
    float2(0.5, 0.5),
    float2(-0.5, 0.5)
};

static float3 colors[3] = {
    float3(1.0, 0.0, 0.0),
    float3(0.0, 1.0, 0.0),
    float3(0.0, 0.0, 1.0)
};

VS_OUTPUT VS_Main(int index:SV_VertexID)
{
  VS_OUTPUT result;
  result.vPosition.xy = positions[index].xy;
  result.vDiffuse.rgb = colors[index].rgb;
  return result;
}