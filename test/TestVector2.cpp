#include <UnitTest++.h>
#include <Fragment\Vector2.h>

struct Vector2Fixture
{
   Vector2Fixture() 
   { 
      v.x = 3;
      v.y = 3;
   }
   
   ~Vector2Fixture() 
   {
   
   }

   Fragment::Vector2 v;
};

TEST_FIXTURE(Vector2Fixture, TestVector2)
{
   CHECK_EQUAL(v.x, 3);
   CHECK_EQUAL(v.x, 3);
}