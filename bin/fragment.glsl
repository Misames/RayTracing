#version 330

uniform vec3 view_pos;
uniform vec3 lightPos;

varying vec3 v_normal;
varying vec3 v_color_light;
varying vec3 v_color_obj;
varying vec3 FragPos;

void main()
{
    float ambientStrength = 1.0;
    vec3 ambient = ambientStrength * v_color_light;

    vec3 norm = normalize(v_normal);
    vec3 lightDir = normalize(lightPos - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * v_color_light;

    float specularStrength = 0.5;
    vec3 viewDir = normalize(view_pos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    vec3 specular = specularStrength * spec * v_color_light;

    vec3 result = (ambient + diffuse + specular) * v_color_obj;
    gl_FragColor = vec4(result, 1.0);
}