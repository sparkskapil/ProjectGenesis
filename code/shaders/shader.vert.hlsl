struct VS_INPUT
{
    uint vertexID : SV_VertexID;
};

struct VS_OUTPUT
{    
    float4 position : SV_Position;
    float3 color : COLOR0;
};

static float2 positions[3] = { float2(0.0, -0.5), float2(0.5, 0.5), float2(-0.5, 0.5) };
static float3 colors[3] = { float3(1.0, 0.0, 0.0), float3(0.0, 1.0, 0.0), float3(0.0, 0.0, 1.0) };

VS_OUTPUT VS_Main(VS_INPUT input)
{
    VS_OUTPUT output;
    output.position = float4(positions[input.vertexID], 0.0, 1.0);
    output.color = colors[input.vertexID];
    return output;
}