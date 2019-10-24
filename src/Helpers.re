[@bs.send] external toString : Js.t('a) => string = "toString";

module Element = {
  type elementT;
  [@bs.set] external setInnerHTML : (elementT, string) => unit = "innerHTML";
  [@bs.get] external getInnerHTML : elementT => string = "innerHTML";
  [@bs.set] external setValue : (elementT, string) => unit = "value";
  [@bs.get] external getValue : elementT => string = "value";
  [@bs.send]
  external addEventListener : (elementT, string, unit => unit) => unit =
    "addEventListener";
};

module Document = {
  [@bs.val]
  external getElementById : string => Element.elementT =
    "document.getElementById";
  [@bs.val]
  external addEventListener : (string, unit => unit) => unit =
    "document.addEventListener";
};
