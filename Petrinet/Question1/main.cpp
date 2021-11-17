#include "../Graph.h"
int main()
{
   PetriNet p;
   string arr_State[] = {"Free", "Busy", "Docu"};
   int arr_Tokens[] = { 1, 0, 0};
   string arr_Trans[] = {"Start", "Change", "End"};
   p.add_State(arr_State, arr_Tokens, 3);
   p.add_Transition(arr_Trans, 3);
   p.Edge_STS("Free", "Start", "Busy");
   p.Edge_STS("Busy", "Change", "Docu");
   p.Edge_STS("Docu", "End", "Free");
   p.firing();
   p.marking();
}