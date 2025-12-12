# Footlight

A stage lighting control app for regular people.

The plan is to be similar to PC stage, with the same simplicity of use, just
multi platform, still supported on current hardware, and able to connect to anything Art-net.

## Ideology

- Just one use case - an amateur theatre show. A play. A list of pre-defined cues, using pre-defined scenes.
- Does NOT need to be able to run live lighting music shows. Just runs theatre performances.
- It Just Works. Not complicated to use; not overly complicated to program.
- New volunteer should be able to RUN a show with one minute's demo.
- New volunteer should be able to PROGRAM a show with (five minutes? one hour?) worth of training.

## One Important thing

Each scene should be independent.

- If I run a scene, it shouldn't matter what I ran before, or earlier that day, or last Tuesday.
- If I run a scene, I want to see that scene exactly the same as every other time I run that scene.
- Therefore, the software MUST NOT leave any fixtures the same as they were in a previous scene 
        (at least, not if the master dimmer is > 0).
- Every fixture must be how I set it FOR THAT SCENE.

The only excption is that fixtures with master dimmer set to zero - ie they are showing no light at all -
can be pre-set to the right location (or gobo etc) for a future cue in the cue list. Or left at
whatever they were before. Don't care ... PROVIDED the master dimmer is zero.

## Desired features

- Blind mode - edit a scene while a different one is active on stage
- Automatic move-in-black (user doesn't need to think about it)
- All fixtures to 0% dimmer when not explicitly included
- Control fixture movement by moving something on screen, not two sliders (With limits, so not TOO far)
- Color selection via colour selection, not three sliders
- Can control eg dimmer for all selected fixtures in one control
- Can control RGB, or Movement, for all selected fixtures in one control
- "Lock Changes" toggle for read-only

## Will Not Include (version 1.0 at least)

- No sound playback. Just lights.
- No direct USB or sACN. Just Art-Net.
- No automatic discovery.
- No Master Dimmer for the whole app. Not needed, and risks someone accidentally putting it to 0% and not knowing how to get the lights back on.

## Might not include (might leave to v2.0)

- Infinte Undo

## Simple interface

- Set up fixtures
- Set up scenes (from fixtures)
- Set up cuelists (from scenes)

## Cue List

- Default fade in / out for list (eg 1 sec or 3 secs)
- Each cue can override
- Preferences - default fade in / fade out for new cue lists

## Thoughts

Ideally I’d get a copy of [Light Bytes](https://artisticlicence.com/products/light-bytes)
by Wayne Howell (the guy that made Art-Net),
but it’s $238 AUD, when shipping from the UK to Australia is included. (They don't sell an online version.)

If you have a colour or position or dimmer value on one fixture, and you want to copy it to one or more other fixtures, you might only want to copy the colour, not position. Or position and colour, but not dimmer value, etc. And of course it needs to be a natural, discoverable user interface. :-)

## Fixture Definition Format

As per [this suggestion](https://github.com/OpenLightingProject/open-fixture-library/issues/4973)
on the [Open Fixture Library](https://github.com/OpenLightingProject/open-fixture-library),
I will use the current OFL fixture format, but freeze it in place via a new export plugin.

Or possibly just copy the [DragronFrame plugin](https://open-fixture-library.org/about/plugins/dragonframe),
which is the same thing but from a little while ago, and use that.

Or heck, maybe don't bother, and just use the [GDTF format](https://gdtf-share.com) natively.

## File Format

Just do the same as QLC+ maybe?

No. Do something simple with QT's JSON stuff,
like [this demo](https://doc.qt.io/qt-6/qtcore-serialization-savegame-example.html).
