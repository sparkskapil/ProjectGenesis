struct VS_OUTPUT
{
    float3 color : COLOR0;
};

struct PS_OUTPUT
{
    float4 color : SV_Target0;
};

PS_OUTPUT PS_Main(VS_OUTPUT input)
{
    PS_OUTPUT output;
    output.color = float4(input.color, 1.0);
    return output;
}