unit CrustObject;

{$mode objfpc}{$H+}
{$m+}

interface

uses
  Classes, SysUtils, TypInfo;

type

  TCrustObject = class;

  TCrustEvent = procedure(Sender: TCrustObject; EventTag: Integer); stdcall;


  { TCrustObject }

  TCrustObject = class abstract
  private
    fId: Integer;
    fName: AnsiString;
    fPropCount: Integer;
    fTag: Integer;
    function GetProp(Index: Integer): AnsiString;
    procedure SetProp(Index: Integer; AValue: AnsiString);
  protected
    fTypeData: PTypeData;
    fPropList: PPropList;
  public
    constructor Create;
    destructor Destroy; Override;
  public
    procedure AddEventListener(anEventName: AnsiString; anEventFunction: TCrustEvent);
    procedure RemoveEventListener(anEventName: AnsiString);
    procedure DispatchEvent(anEventName: AnsiString);

    function GetAttrS(aProp: AnsiString): AnsiString;
    function GetAttrI(aProp: AnsiString): Integer;
    function GetAttrF(aProp: AnsiString): Single;

    procedure SetAttrS(aProp, aValue: AnsiString);
    procedure SetAttrI(aProp: AnsiString; aValue: Integer);
    procedure SetAttrF(aProp: AnsiString; aValue: Single);
  public
    property Attr[aProp: AnsiString]: AnsiString read GetAttrS write SetAttrS;
    property AttrI[aProp: AnsiString]: Integer read GetAttrI write SetAttrI;
    property AttrF[aProp: AnsiString]: Single read GetAttrF write SetAttrF;

    property Prop[Index: Integer]: AnsiString read GetProp write SetProp;
  published
    property ID: Integer read fId write fID;
    property Tag: Integer read fTag write fTag;
    property Name: AnsiString read fName write fName;

    property PropCount: Integer read fPropCount;
  end;

implementation

{ TCrustObject }

function TCrustObject.GetProp(Index: Integer): AnsiString;
begin

end;

procedure TCrustObject.SetAttrS(aProp: AnsiString; AValue: AnsiString);
begin

end;

procedure TCrustObject.SetProp(Index: Integer; AValue: AnsiString);
begin

end;

constructor TCrustObject.Create;
begin
  fTypeData := GetTypeData(Self.ClassInfo);
  GetMem(fPropList, fTypeData^.PropCount * SizeOf(Pointer));
  fPropCount := GetPropList(Self.ClassInfo, [tkInteger, tkFloat, tkSString, tkLString, tkAString, tkWString, tkBool, tkInt64, tkQWord, tkUString], fPropList);
end;

destructor TCrustObject.Destroy;
begin
  FreeMem(fPropList, fTypeData^.PropCount * SizeOf(Pointer));

  inherited Destroy;
end;

procedure TCrustObject.AddEventListener(anEventName: AnsiString;
  anEventFunction: TCrustEvent);
begin

end;

procedure TCrustObject.RemoveEventListener(anEventName: AnsiString);
begin

end;

procedure TCrustObject.DispatchEvent(anEventName: AnsiString);
begin

end;

function TCrustObject.GetAttrS(aProp: AnsiString): AnsiString;
begin

end;

function TCrustObject.GetAttrI(aProp: AnsiString): Integer;
begin

end;

function TCrustObject.GetAttrF(aProp: AnsiString): Single;
begin

end;

procedure TCrustObject.SetAttrS(aProp: AnsiString; aValue: AnsiString);
begin

end;

procedure TCrustObject.SetAttrI(aProp: AnsiString; aValue: Integer);
begin

end;

procedure TCrustObject.SetAttrF(aProp: AnsiString; aValue: Single);
begin

end;

end.

