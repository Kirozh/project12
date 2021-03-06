#ifndef __Sound_H
#define __Sound_H 1

class window;

class Sound
{
public:
	virtual ~Sound() = 0;

	virtual void release(void) = 0;

	virtual void play(long lStartPosition = 0, bool bLoop = 0) = 0;

	virtual void play(bool bLoop = 0) = 0;

	virtual void stop(void) = 0;

	virtual void pause(void) = 0;

	virtual void resume(void) = 0;


};

typedef Sound* (*PFNCREATESOUNDPROC)(const window& cwnd);

#endif // !__Sound_H

