struct PS_INPUT
{
    float4  vPosition : POSITION;
    float4  vDiffuse : COLOR;
};

float4 PS_Main(PS_INPUT input) : SV_TARGET
{
  float4 color;
  color.rgb = input.vDiffuse.rgb;
  return color;
}