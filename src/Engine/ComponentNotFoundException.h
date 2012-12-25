#include "GameEngineException.h"

class ComponentNotFoundException : public GameEngineException{
    public:
        ComponentNotFoundException(const std::string componentName)
        {
            message = "Component " + componentName + " not found\n";
        }
};
