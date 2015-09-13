/* Copyright (c) 2011 Kevin Wells */
/* Floating Point Colors may be freely redistributed.  See license for details. */

#ifndef timer_h
#define timer_h

class Timer{
    private:
    float start_ticks;/**The clock time when the timer started.*/
    float paused_ticks;/**The ticks stored when the timer was paused.*/
    /**Timer status.*/
    bool paused;
    bool started;
    public:
    Timer();/**Initializes variables.*/
    /**The various clock actions.*/
    void start();
    void stop();
    void pause();
    void unpause();
    float get_ticks();/**Get the timer's time.*/
    /**Checks the status of the timer.*/
    bool is_started();
    bool is_paused();
};

#endif
