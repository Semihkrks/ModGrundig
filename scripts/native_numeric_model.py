"""Explicit demonstration channel service for the native-frame design lab.

Never substitutes the tuned service name for the typed destination. A real TV
adapter must resolve display number through GetProgramSelInfo before looking
up the destination name; this module is intentionally not that adapter.
"""
import json
from pathlib import Path

ROOT=Path(__file__).resolve().parents[1]
FIXTURE=ROOT/'ui-preview/channels.json'

def channels():
    data=json.loads(FIXTURE.read_text(encoding='utf-8'))
    if data.get('demo') is not True or data.get('device_data_verified') is not False:
        raise ValueError('Expected explicitly marked demonstration channels')
    result=[]
    seen=set()
    for channel in data['channels']:
        number,name=channel['number'],channel['name']
        if type(number) is not int or not 1<=number<=99999 or number in seen:
            raise ValueError('Invalid or duplicate demonstration channel number')
        if not isinstance(name,str) or not 1<=len(name)<=80 or any(ord(c)<32 for c in name):
            raise ValueError('Invalid demonstration channel name')
        seen.add(number)
        result.append(dict(number=number,name=name))
    return result

def resolve(digits):
    if not isinstance(digits,str) or not digits.isascii() or not digits.isdigit() or not 1<=len(digits)<=5:
        raise ValueError('Expected 1..5 ASCII digits')
    match=next((c for c in channels() if c['number']==int(digits)),None)
    return dict(digits=digits,number=int(digits),matched=match is not None,
                name=match['name'] if match else 'Kayıtlı kanal yok',
                source='ui-preview/channels.json: user-authorized demo fixture',
                device_database=False,native_name_bridge_installed=False)
