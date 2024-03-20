//
// Created by Daniel Chiliaev on 18/03/2024.
//

#ifndef STATE_WALKING_H
#define STATE_WALKING_H
//#include "../keyboard.h"
#include "../State.h"

class State;
namespace states {
    class WalkingState : public State {
    public:
        void update_position(int type, FSM *fsm, int direction) {
            if (Keyboard::getInstance().get_key() == (type)) {
               //printw("213");
                FSMGame *fsm1 = dynamic_cast<FSMGame *>(fsm);
                if (fsm1->this_room->conection[direction] != nullptr) {
                    fsm1->this_room = fsm1->this_room->conection[direction];
                }
            }
        }

        void Handle(FSM *fsm) override {

        };

        void Update(FSM *fsm) override {
            update_position((int)KeyboardKey::w, fsm, 0);
            update_position((int)KeyboardKey::s, fsm, 2);
            update_position((int)KeyboardKey::d, fsm, 1);
            update_position((int)KeyboardKey::a, fsm, 3);
        };

        void Render(FSM *fsm) override {};

        void OnEnter(FSM *fsm) override {

        };

        void OnExit(FSM *fsm) override {
        };
    };
} // namespace states
#endif // STATE_WALKING_H
