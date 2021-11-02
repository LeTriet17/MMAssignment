#include "Graph.h"
int main()
{
  PetriNet p;
  string arr_State[] = {"wait", "before", "after", "gone","free","occupied"};
  int arr_Tokens[] = {3, 0, 0, 0,1,0};
  string arr_Trans[] = {"enter", "make_photo", "leave"};
  p.add_State(arr_State, arr_Tokens, 6);
  p.add_Transition(arr_Trans, 3);
  p.Edge_STS("wait", "enter","before");
  p.Edge_STS("before", "make_photo", "after");
  p.Edge_STS("after", "leave", "gone");
  p.Edge_TST("leave","free","enter");
  p.Edge_TST("enter", "occupied", "leave");

  p.marking();
  p.firing();
  p.marking();
  p.firing();
  p.marking();
  p.firing();
  p.marking();
  p.firing();
  p.marking();
}