/**
 * Abstract templated class that defines an animation.
 * 
 * @author Francis BISSON
 */

#ifndef ANIMATION_HPP
#define ANIMATION_HPP

// INCLUDES ////////////////////////////////////////////////////////////////////
#include <list>

#include "Debug.h"
#include "KeyFrame.hpp"
#include "Utility.h"

// CLASS DEFINITION ////////////////////////////////////////////////////////////
template<class ValueType>
class Animation
{
public:
	typedef				KeyFrame<ValueType>		KeyFrameType;
	typedef	typename	std::list<KeyFrameType>	KeyFrameList;
	typedef	typename	KeyFrameList::iterator	KeyFrameIterator;
	
						 Animation();
	virtual				~Animation();
	
	void				AddKeyFrame(const KeyFrameType& keyFrame);
	
	void				Start();
	void				Update(double deltaTime, double totalTime);
	
	bool				IsFinished() const { return m_Finished; }

protected:
	virtual	void		SetValue(const ValueType& value) = 0;
	virtual	ValueType	BlendValues(const KeyFrameType& current, const KeyFrameType& next, double percentage) = 0;
	
	KeyFrameList		m_KeyFrames;
	
	double				m_AnimStartTime;
	
	bool				m_Started;
	bool				m_Finished;
};

// IMPLEMENTATION //////////////////////////////////////////////////////////////
template<class ValueType>
Animation<ValueType>::Animation()
:m_AnimStartTime(-1.0)
,m_Started(false)
,m_Finished(false)
{
}

template<class ValueType>
Animation<ValueType>::~Animation()
{
}

template<class ValueType>
void Animation<ValueType>::AddKeyFrame(const KeyFrameType& keyFrame)
{
#ifndef NDEBUG
	if(!m_KeyFrames.empty())
	{
		DEBUG_ASSERT(m_KeyFrames.back().GetTime() <= keyFrame.GetTime());
	}
#endif
	
	m_KeyFrames.push_back(keyFrame);
}

template<class ValueType>
void Animation<ValueType>::Start()
{
	DEBUG_ASSERT(!m_Started);
	DEBUG_ASSERT(!m_KeyFrames.empty());
	
	m_Started = true;
}

template<class ValueType>
void Animation<ValueType>::Update(double deltaTime, double totalTime)
{
	UNUSED(deltaTime);
	
	if(m_Started && !IsFinished())
	{
		if(m_AnimStartTime < 0.0)
		{
			m_AnimStartTime = totalTime;
		}
		
		double animTotalTime = totalTime - m_AnimStartTime;
		if(animTotalTime >= m_KeyFrames.back().GetTime())
		{
			m_Finished = true;
			return;
		}
		
		KeyFrameIterator first = m_KeyFrames.begin();
		KeyFrameType currentFrame		= *first;
		KeyFrameType nextFrame			= *(++first);
		
		if(animTotalTime >= currentFrame.GetTime())
		{
			if(animTotalTime >= nextFrame.GetTime())
			{
				// The current frame is finished
				m_KeyFrames.pop_front();
				
				SetValue(nextFrame.GetValue());
			}
			else if(currentFrame.IsBlended())
			{
				double frameTotalTime = nextFrame.GetTime() - currentFrame.GetTime();
				double frameTime = totalTime - currentFrame.GetTime(); 
				double percentage = frameTime / frameTotalTime;
				
				ValueType value = BlendValues(currentFrame, nextFrame, percentage);
				SetValue(value);
			}
			else
			{
				SetValue(currentFrame.GetValue());
			}
		}
	}
}

#endif // ANIMATION_HPP
