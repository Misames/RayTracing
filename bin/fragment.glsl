varying vec2 v_texcoords;
uniform sampler2D u_sampler;

void main()
{
    vec4 color = texture2D(u_sampler, v_texcoords);
    gl_FragColor = color;
}