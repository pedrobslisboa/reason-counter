open Helpers;

// import styles for bs-css
Styles.global;

// types
type actionType =
  | Increase
  | Decrease
  | Clear;

let state = ref(0);

let button = actionType =>
  switch (actionType) {
  | Increase => Document.getElementById("increase")
  | Decrease => Document.getElementById("decrease")
  | Clear => Document.getElementById("clear")
  };

let display = Document.getElementById("display");
let updateDisplay = value =>
  value^ |> string_of_int |> Element.setInnerHTML(display);

let handleClick = (actionType, callback) => {
  switch (actionType) {
  | Increase => state := state^ + 1
  | Decrease => state := state^ - 1
  | Clear => state := 0
  };

  callback(state);
};

let buttonEvent = actionType =>
  Element.addEventListener(button(actionType), "click", () =>
    handleClick(actionType, updateDisplay)
  );

buttonEvent(Increase);
buttonEvent(Decrease);
buttonEvent(Clear);