unit CrustNode;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, CrustObject;

type
  TCrustNode = class(TCrustObject)
  published
    property X: Single read fX write fX;
    property Y: Single read fY write fY;

    property Left: Single read fX write fX;
    property Top: Single read fY write fY;
    property Right: Single read fRight write fRight;
    property Bottom: Single read fBottom write fBottom;
  end;

implementation

end.

