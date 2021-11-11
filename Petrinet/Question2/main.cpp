#include "../Graph.h"
int main()
{
   PetriNet p;
   string arr_State[] = {"Wait", "Inside", "Done"};
   int arr_Tokens[] = {5, 0, 1};
   string arr_Trans[] = {"Start", "Change"};
   p.add_State(arr_State, arr_Tokens, 3);
   p.add_Transition(arr_Trans, 2);
   p.Edge_STS("Wait", "Start", "Inside");
   p.Edge_STS("Inside", "Change", "Done");
   p.run();
}