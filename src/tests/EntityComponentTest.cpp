#include "../Engine/Entity.h"
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/CompilerOutputter.h>

using namespace Engine;

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
    CPPUNIT_TEST( testChangeComponents );
    CPPUNIT_TEST_SUITE_END();
    
    Entity *e;
    
    
    public:
    void setUp(){
        e = new Entity("test");
        e->addComponent("1", new TestComponent("Hello 1"));
        e->addComponent("2", new TestComponent("Hello 2"));
    }
    
    void tearDown(){
        delete e;
    }

    void testGetComponents()
    {
        auto first = e->getComponent<TestComponent>("1");
        auto second = e->getComponent<TestComponent>("2");

        CPPUNIT_ASSERT(first->msg == "Hello 1");
        CPPUNIT_ASSERT(second->msg == "Hello 2");
        
    }

    void testChangeComponents()
    {
        auto c = e->getComponent<TestComponent>("1");

        c->msg = "Changed message";

        c = e->getComponent<TestComponent>("1");

        CPPUNIT_ASSERT(c->msg == "Changed message");
    }


};


CPPUNIT_TEST_SUITE_REGISTRATION( EntityComponentTest );


int main(int argc, char *argv[])
{

    CppUnit::Test *suite = CppUnit::TestFactoryRegistry::getRegistry().makeTest();

    // Adds the test to the list of test to run
    CppUnit::TextUi::TestRunner runner;
    runner.addTest( suite );

    // Change the default outputter to a compiler error format outputter
    runner.setOutputter( new CppUnit::CompilerOutputter( &runner.result(),
                std::cerr ) );
    // Run the tests.
    bool wasSucessful = runner.run();

    // Return error code 1 if the one of test failed.
    return wasSucessful ? 0 : 1;
}
