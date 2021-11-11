#include "Graph.h"
int main()
{
  PetriNet p;
  string arr_State[] = {"Wait", "Inside", "Done", "Free","Busy","Docu"};
  int arr_Tokens[] = {4, 0, 1, 1,0,0};
  string arr_Trans[] = {"Start", "Change", "End"};
  p.add_State(arr_State, arr_Tokens, 6);
  p.add_Transition(arr_Trans, 3);
  p.Edge_STS("Free", "Start","Busy");
  p.Edge_STS("Wait", "Start", "Inside");
  p.Edge_STS("Busy", "Change", "Docu");
  p.Edge_STS("Inside","Change","Done");
  p.Edge_STS("Docu", "End", "Free");
  p.run();
}