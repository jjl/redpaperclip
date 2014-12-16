function redpaperclip_transmit(type, id) {

}
function redpaperclip_handle(e) {
//https://developer.mozilla.org/en-US/docs/Web/Events
    switch (e.type) {
	case "mouseEvent":
	case "kbEvent":
	case "textEvent":
	case "uiEvent":
	case "messageEvent":
	case "mutationEvent":
	default:
	redpaperclip_transmit(e.type, e.target.id);
    }
    e.stopPropagation();
}
// Only watches for events that change big things
function redpaperclip_watchImportant(el) {
    if () {}
}

// Watches for all changes on an element
function redpaperclip_watchAll(el) {
}

//  var function
//structural
//nonstructural
  var events = [
    "beforecopy", "beforecut", "beforepaste", "beforeunload", "blur", "change",
    "copy", "cut", "focus", "hashchange", "input", "load", "paste",
    "radiostatechange", "reset", "resize", "scroll", "search", "select",
    "selectstart", "submit", "unload",
    // mouse
    "click", "contextmenu", "dblclick", "drag", "dragend", "dragenter",
    "dragleave", "dragover", "dragstart", "drop", "mousedown", "mousemove",
    "mouseout", "mouseover", "mouseup", "mousewheel", 
    // keyboard
    "keydown", "keypress", "keyup", 
    // text
    "textInput",
    // ui
    "DOMActivate", "DOMFocusIn", "DOMFocusOut",
    // message
    "message",
    // overflow
    "overflowchanged",
    // mutation
    "DOMCharacterDataModified"
  ];
})();
