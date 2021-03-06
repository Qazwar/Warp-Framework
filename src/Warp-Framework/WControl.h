// � 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_CONTROL_H_
#define _W_CONTROL_H_

#include "WGFXContainer.h"
#include "WRect.h"
#include "IControl.h"
#include "WPoint.h"
#include "WRect.h"
#include "WContainer.h"
#include "WMouse.h"
#include "WColorTransform.h"

class WControl : public IControl
{
public:
	WControl(W_INT zIndex = 0);
	WControl(W_FLOAT top, W_FLOAT left, W_FLOAT bottom, W_FLOAT right, W_INT zIndex = 0);
	WControl(WPointF topleft, WPointF botright, W_INT zIndex = 0);
	WControl(WRectF location, W_INT zIndex = 0);
	virtual ~WControl(void);

	virtual WRectF Location(W_FLOAT top, W_FLOAT left, W_FLOAT bottom, W_FLOAT right);
	virtual WRectF Location(WPointF topleft, WPointF botright);
	virtual WRectF Location(WRectF location);

	virtual WRectF RelLocation(W_FLOAT top, W_FLOAT left, W_FLOAT height, W_FLOAT width);
	virtual WRectF RelLocation(WPointF topleft, WPointF heightwidth);
	virtual WRectF RelLocation(WRectF location);

	virtual WRectF Location(void) const;

	virtual void Render(void) override = 0;

	virtual WPointF Displace(W_FLOAT X, W_FLOAT Y);
	virtual WPointF Displace(WPointF XY);

	virtual WRegistry* KeyDownRegistery(void);
	virtual WRegistry* KeyUpRegistery(void);
	virtual WRegistry* KeyCharRegistery(void);
	virtual WRegistry* MouseDownRegistery(void);
	virtual WRegistry* MouseUpRegistery(void);
	virtual WRegistry* MouseEnterRegistery(void);
	virtual WRegistry* MouseLeaveRegistery(void);
	virtual WRegistry* MouseRollUpRegistery(void);
	virtual WRegistry* MouseRollDownRegistery(void);

	virtual WRegistry* KeyDownRegistery(WRegistry* intake);
	virtual WRegistry* KeyUpRegistery(WRegistry* intake);
	virtual WRegistry* KeyCharRegistery(WRegistry* intake);
	virtual WRegistry* MouseDownRegistery(WRegistry* intake);
	virtual WRegistry* MouseUpRegistery(WRegistry* intake);
	virtual WRegistry* MouseEnterRegistery(WRegistry* intake);
	virtual WRegistry* MouseLeaveRegistery(WRegistry* intake);
	virtual WRegistry* MouseRollUpRegistery(WRegistry* intake);
	virtual WRegistry* MouseRollDownRegistery(WRegistry* intake);

	virtual W_INT ZIndex(void) const override;
	virtual bool IsActive(void) const override;
	virtual bool IsEnabled(void) const override;
	virtual bool IsVisible(void) const override;

	virtual W_INT ZIndex(W_INT input) override;
	virtual bool IsActive(bool input) override;
	virtual bool IsEnabled(bool input) override;
	virtual bool IsVisible(bool input) override;

	virtual void KeyDown(WKeyboardArgs* Args) override;
	virtual void KeyUp(WKeyboardArgs* Args) override;
	virtual void KeyChar(WKeyboardArgs* Args) override;
	virtual void MouseDown(WMouseArgs* Args) override;
	virtual void MouseUp(WMouseArgs* Args) override;
	virtual void MouseEnter(WMouseArgs* Args) override;
	virtual void MouseLeave(WMouseArgs* Args) override;
	virtual void MouseRollUp(WMouseArgs* Args) override;
	virtual void MouseRollDown(WMouseArgs* Args) override;

	virtual WControl* Parent(WControl* intake);
	virtual WControl* Parent(void) const;

	virtual W_FLOAT XOffset(void) const;
	virtual W_FLOAT XOffset(W_FLOAT intake);

	virtual W_FLOAT YOffset(void) const;
	virtual W_FLOAT YOffset(W_FLOAT intake);

	virtual void UpdateRect(void);
	virtual bool IsWithin(WMouseArgs* Args) const;
	virtual void SetZIndexNoChange(W_INT zIndex) override;
	virtual W_INT GetWidth(void) const;
	virtual W_INT GetHeight(void) const;

protected:
	// Normal
	W_INT m_zIndex;
	W_FLOAT m_xoffset;
	W_FLOAT m_yoffset;

	bool m_isActive;
	bool m_isClicked;
	bool m_isEnabled;
	bool m_isVisible;

	W_FLOAT m_top;
	W_FLOAT m_left;
	W_FLOAT m_bottom;
	W_FLOAT m_right;

	WRectF ctRec;

	WRegistry* WCTKeyDownRegistery;
	WRegistry* WCTKeyUpRegistery;
	WRegistry* WCTKeyCharRegistery;

	WRegistry* WCTMouseDownRegistery;
	WRegistry* WCTMouseUpRegistery;

	WRegistry* WCTMouseEnterRegistery;
	WRegistry* WCTMouseLeaveRegistery;

	WRegistry* WCTMouseRollUpRegistery;
	WRegistry* WCTMouseRollDownRegistery;

	WControl* m_Parent;
};

#endif // !_W_CONTROL_H_
