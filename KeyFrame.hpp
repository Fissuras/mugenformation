/**
 * Templated class that defines a keyframe in an animation.
 * 
 * @author Francis BISSON
 */

#ifndef KEYFRAME_HPP
#define KEYFRAME_HPP

// CLASS DEFINITION ////////////////////////////////////////////////////////////
template<class ValueType>
class KeyFrame
{
public:
					 KeyFrame(double time, bool blended, const ValueType& value);
	virtual			~KeyFrame();
	
	double			GetTime() const		{ return m_Time; }
	bool			IsBlended() const	{ return m_Blended; }
	
	ValueType		GetValue() const	{ return m_Value; }

protected:
	double			m_Time;
	bool			m_Blended;
	
	ValueType		m_Value;			
};

// IMPLEMENTATION //////////////////////////////////////////////////////////////
template<class ValueType>
KeyFrame<ValueType>::KeyFrame(double time, bool blended, const ValueType& value)
:m_Time(time)
,m_Blended(blended)
,m_Value(value)
{
}

template<class ValueType>
KeyFrame<ValueType>::~KeyFrame()
{
}

#endif // KEYFRAME_HPP
