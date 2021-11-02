#ifndef GRAPH_H
#define GRAPH_H
#include "main.h"

using namespace std;
class PetriNet
{
   class Transition;
   class State
   {
   private:
      string name;
      int tokens;
      bool marked;
      PetriNet *graph;

   public:
      list<Transition *> adj_Transitions;
      State(string name, int tokens, PetriNet *graph) : name(name), tokens(tokens), marked(false), graph(graph) {}
      State() : name(""), tokens(0), marked(false), graph(NULL) {}
      void decreaseTokens() { this->tokens--; }
      void increaseTokens() { this->tokens++; }
      int getTokens() { return tokens; }
      string getName() { return name; }
   };
   class Transition
   {
      string name;
      vector<string> prevState, nextState;
      bool enabled;
      PetriNet *graph;

   public:
      list<State *> adj_States;
      Transition(string name, PetriNet *graph) : name(name), enabled(false), graph(graph) {}
      Transition() : name(""), enabled(false), graph(NULL) {}
      vector<string> prevStates() { return this->prevState; }
      vector<string> nextStates() { return this->nextState; }
      void setPrevState(string prevState) { this->prevState.push_back(prevState); }
      void setNextState(string nextState) { this->nextState.push_back(nextState); }
      string getName() { return name; }
      bool isEnabled()
      {
         vector<string> prevStates = this->prevStates();
         for (int i = 0; i < prevStates.size(); i++)
            if (graph->get_State(prevStates[i])->getTokens() < 1)
               return false;
         return true;
      }
   };
   list<State *> states;
   list<Transition *> transitions;
   void connect_Transition(string state, string transition)
   {
      State *s = get_State(state);
      Transition *t = get_Transition(transition);
      t->setPrevState(s->getName());
      s->adj_Transitions.push_back(t);
   }
   void connect_State(string transition, string state)
   {
      State *s = get_State(state);
      Transition *t = get_Transition(transition);
      t->setNextState(s->getName());
      t->adj_States.push_back(s);
   }

public:
   void add_State(string *arr_State, int *arr_tokens, int size)
   {
      for (int i = 0; i < size; i++)
         states.push_back(new State(arr_State[i], arr_tokens[i], this));
   }
   void add_Transition(string *arr_Transition, int size)
   {
      for (int i = 0; i < size; i++)
         transitions.push_back(new Transition(arr_Transition[i], this));
   }
   State *get_State(string name)
   {
      for (list<State *>::iterator it = states.begin(); it != states.end(); it++)
         if ((*it)->getName() == name)
            return *it;
      return NULL;
   }
   list<State *> get_States() { return states; }
   list<Transition *> get_Transitions() { return transitions; }
   Transition *get_Transition(string name)
   {
      for (list<Transition *>::iterator it = transitions.begin(); it != transitions.end(); it++)
         if ((*it)->getName() == name)
            return *it;
      return NULL;
   }
   void Edge_STS(string state1, string transition, string state2)
   {
      connect_Transition(state1, transition);
      connect_State(transition, state2);
   }
   void Edge_TST(string transition1, string state, string transition2)
   {
      connect_State(transition1, state);
      connect_Transition(state, transition2);
   }
   void firing()
   {
      vector<string> update_tokens;
      for (list<Transition *>::iterator it = transitions.begin(); it != transitions.end(); it++)
      {
         if ((*it)->isEnabled())
         {
            vector<string> prevStates = (*it)->prevStates();
            vector<string> nextStates = (*it)->nextStates();
            for (int i = 0; i < prevStates.size(); i++)
            {
               State *state = get_State(prevStates[i]);
               state->decreaseTokens();
            }
            update_tokens.insert(update_tokens.end(), nextStates.begin(), nextStates.end());
         }
      }
      for (int i = 0; i < update_tokens.size(); i++)
      {
         State *state = get_State(update_tokens[i]);
         state->increaseTokens();
      }
   }
   void marking()
   {
      cout << "[ ";
      for (list<State *>::iterator it = states.begin(); it != states.end(); it++)
      {
         list<State *>::iterator tmp = it;
         tmp++;
         if (tmp == states.end())
            cout << (*it)->getTokens() << " ]\n";
         else
            cout << (*it)->getTokens() << ", ";
      }
   }
};
#endif
