#include "scene.hpp"

Scene::Scene() {}

Scene::Scene(const Color bgCol, const Color amCol, vector<Object> listeObj, vector<Light> listeL)
{
    this->AmbianteColor = amCol;
    this->backGroundColor = bgCol;
    this->listeObject = listeObj;
    this->listeLight = listeL;
}

Scene::Scene(const string scenePath = "default")
{
    float r, g, b;
    if (scenePath != "default")
    {
        filebuf fb;
        if (fb.open(scenePath, std::ios::in))
        {
            std::istream is(&fb);

            json j = json::parse(is);
            fb.close();
            r = j.at("/sceneColor/backgroundColorRGB/0");
            g = j.at("/sceneColor/backgroundColorRGB/1");
            b = j.at("/sceneColor/backgroundColorRGB/2");
            backGroundColor = Color(r / 255, g / 255, b / 255);

            r = j.at("/sceneColor/ambiantColorRGB/0");
            g = j.at("/sceneColor/ambiantColorRGB/1");
            b = j.at("/sceneColor/ambiantColorRGB/2");
            backGroundColor = Color(r / 255, g / 255, b / 255);

            for (int i = 0; i < j.at("/nbLights"); i++)
            {
                Vector v = Vector(
                    j.at("/lights/" + to_string(i) + "/position/0"),
                    j.at("/lights/" + to_string(i) + "/position/1"),
                    j.at("/lights/" + to_string(i) + "/position/2"));

                float rot = j.at("/lights/" + to_string(i) + "/rotation");
                float sca = j.at("/lights/" + to_string(i) + "/scale");
                Light nl = Light(v, rot, sca);
                listeLight.push_back(nl);
            }

            for (int i = 0; i < j.at("/nbObjects"); i++)
            {
                Vector v = Vector(
                    j.at("/objects/" + to_string(i) + "/position/0"),
                    j.at("/objects/" + to_string(i) + "/position/1"),
                    j.at("/objects/" + to_string(i) + "/position/2"));

                float rot = j.at("/objects/" + to_string(i) + "/rotation");
                float sca = j.at("/objects/" + to_string(i) + "/scale");

                r = j.at("/objects/" + to_string(i) + "/color/ambiantColorRGB/0");
                g = j.at("/objects/" + to_string(i) + "/color/ambiantColorRGB/1");
                b = j.at("/objects/" + to_string(i) + "/color/ambiantColorRGB/2");

                Color amb = Color(r / 255, g / 255, b / 255);

                r = j.at("/objects/" + to_string(i) + "/color/diffuseColorRGB/0");
                g = j.at("/objects/" + to_string(i) + "/color/diffuseColorRGB/1");
                b = j.at("/objects/" + to_string(i) + "/color/diffuseColorRGB/2");

                Color dif = Color(r / 255, g / 255, b / 255);

                r = j.at("/objects/" + to_string(i) + "/color/specularColorRGB/0");
                g = j.at("/objects/" + to_string(i) + "/color/specularColorRGB/1");
                b = j.at("/objects/" + to_string(i) + "/color/specularColorRGB/2");

                Color spec = Color(r / 255, g / 255, b / 255);

                float shin = j.at("/objects/" + to_string(i) + "/color/shininess");

                Material nm = Material(amb, dif, spec, shin);
                vector<Material> vecMat;
                vecMat.push_back(nm);
                Object nobj = Object(v, rot, sca, vecMat);
                listeObject.push_back(nobj);
            }
        }
    }
}

Color Scene::getBackground() const
{
    return this->backGroundColor;
}

Color Scene::getAmbiant() const
{
    return this->AmbianteColor;
}

int Scene::nbLights() const
{
    return listeLight.size();
}

const Light Scene::getLight(int index) const
{
    return listeLight[index];
}

Object *Scene::closerIntersected(const Ray &ray, Point &impact) const
{
    return nullptr;
}