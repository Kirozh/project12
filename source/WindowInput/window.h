#ifndef __window_H
#define __window_H 1

#ifdef UNICODE
typedef wchar_t TCHAR;
#define TEXT(quote) L##quote
#else
typedef char TCHAR;
#define TEXT(quote) quote
#endif // UNICODE

class window
{
public:
	virtual ~window() = 0;

	// update a window 
	// need to run in a thread that creates the window 
	virtual bool update(void) const = 0;

	// get a handle of a window 
	virtual size_t getHandle(void) const = 0;

	// destroy a window 
	virtual void destroy(void) const = 0;

	// send to close a window 
	virtual void close(void) const = 0;

	// send to show a window 
	virtual void show(void) const = 0;

	// send to minimize a window 
	virtual void minimize(void) const = 0;

	// send to hide a window 
	virtual void hide(void) const = 0;

	// is a window visible 
	virtual bool isVisible(void) const = 0;

	// is a window hide 
	virtual bool isHide(void) const = 0;

	// is a window active 
	virtual bool isActive(void) const = 0;

	// [out] width - get the width of the client area of a window 
	// [out] height - get the height of the client area of a window 
	virtual void getClientAreaSize(long& width, long& height) const = 0;

	// get a parent window of a window
	virtual const window* const getParent(void) const = 0;

	// set the parent window of a window
	virtual void setParent(const window& newParent) const = 0;

	// set the title of a window (ASCII) 
	// [in] title - the new title in ASCII 
	virtual void setTitle(const char* const title) const = 0;

	// set the title of a window (Unicode) 
	// [in] title - the new title in Unicode 
	virtual void setTitle(const wchar_t* const title) const = 0;

};

// [in] title - the title text of the window [default = nullptr ("")]
// [in] width - the width of the client area  [default = 640]
// [in] height - the height of the client area [default = 480]
// [in] icon_path - the path of icon [default = nullptr (without icon)]
// [in] parent - pointer to the parent window of the window [default = nullptr (without a parent window)]
typedef window* (*PFNCREATEWINDOWPROC)(
	const TCHAR* const title /* = nullptr */,
	const long width /* = 640 */,
	const long height /* = 480 */,
	const TCHAR* const icon_path /* = nullptr */,
	const window* const parent /* = nullptr */
);



#endif // !__window_H
