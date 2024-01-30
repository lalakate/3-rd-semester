#ifndef FLAPPY_BIRD_COURSE_WORK_STATE_H
#define FLAPPY_BIRD_COURSE_WORK_STATE_H

class State {
public:
    virtual void Init() = 0;

    virtual void HandleInput() = 0;

    virtual void Update(float dt) = 0;

    virtual void Draw(float dt) = 0;

    virtual void Pause() {}

    virtual void Resume() {}
};

#endif //FLAPPY_BIRD_COURSE_WORK_STATE_H
