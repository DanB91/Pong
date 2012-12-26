#include "../Engine/Entity.h"
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/HelperMacros.h>

class TestComponent : public Component{
    public:
        TestComponent(std::string msg)
            : msg(msg)
        {}

        std::string msg;
};

class EntityComponentTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE( EntityComponentTest );
    CPPUNIT_TEST( testGetComponents );
    CPPUNIT_TEST_SUITE_END();
    Entity e;
    
    
    public:
    void setUp(){
        e.addComponent("1", new TestComponent("Hello 1"));
        e.addComponent("2", new TestComponent("Hello 2"));
    }

    void testGetComponents()
    {
        TestComponent &first = static_cast<TestComponent&>(e.getComponent("1"));
        TestComponent &second = static_cast<TestComponent&>(e.getComponent("2"));

        CPPUNIT_ASSERT(first.msg == "Hello 1");
        CPPUNIT_ASSERT(second.msg == "Hello 2");
        
    }


};

int main(void)
{
    CppUnit::TextUi::TestRunner run;
    CppUnit::TestFactoryRegistry &r = CppUnit::TestFactoryRegistry::getRegistry();
    run.addTest(r.makeTest());

    run.run("", false, true);

    return 0;
}
