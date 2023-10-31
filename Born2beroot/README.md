Virtual Machine
Uses software instead of a physical computer to run programs or apps. Each VM has its own operating system and functions separately, so it is possible to have more than one VM per machine. Can be used to test applications in a safe, separate environment.

#Operating Systems
Options : Debian vs Rocky
-Debian-
*Oldest operating system based on Linux kernel = long standing reputation for its robustness, stability and massic software repositories = verstaile option for various server applications
*Uses AppArmor as its primary mandatory access control system and is easier to set up and manage
*.deb packages by apt (advanced packaging tool) as package manager which is more reliable and efficient (but may not offer same level of flexibility, especially for complex software deployments)

-Rocky-
*Has substantial similarity to Red Hat Enterprise Linux (RHEL) and superior support for Security-Enhanced Linux(SELinux)
*SELinux is a security module that supports access control security policies, playing a vital role in server security and is supported by Debian as well, just that Rocky OS integrates it more closely, echoing the strong SELinux policies of RHEL (considered more flexible and robust, offering fine-grained controls and policy configurations)
*.rpm packages by YUM and its successor, dnf as package manager (powerful, flexible an easy to use)

#Packaging Manager
Differences: Apt vs Aptitude (dpkg -> APT (command line) -> Aptitude (command line) OR Synaptic (graphical))
-Aptitude is a high-level package manager while APT is lower level package manage which can be used by other higher-level package managers 
-Apt offers command-line interface VS Aptitiude offers visual interface
-When facing a package conflict, Apt will not fix the issue while Aptitude will suggest a resolution that can do the job
-Aptitude can interactively retrive and display the Debian changelog of all available official packages

#Security System
Differences: SELinux vs APPArmor
Access Control
-SELinux uses security policies based on file labels (unless a policy is defined for a process, app or directory, it won't allow access to it) VS 
AppArmor uses policies that are based on paths(uses profiles to determine what files and permissions an application requires) & provides mandatory access control(MAC) to supplement traditional discretionary access control

-SELinux uses both MLS (multilevel security) & MCS(multicategory security) VS 
APPArmor uses neither
-MLS-
*enforces Bell-LaPadula mandatory access model which defines users and processes as subjects. Files, devices and other components are objects. Both subjects and objects are given a security level that defines a subject's clearance or an object's classifications
-MCS-
*uses categories that are attached to objects and granted to subjects

Components
-SELinux composes of key components: Subject, Access Vector Cache, Security Server, SELinux Policy Database, Objects, Kernel module VS 
AppArmor uses the following: server analyser (scans ports and determines which applications are listening, also detects if an application doesn't have a profile and if the server need to confine it), profile generator, optimizer

Policy rules and control levels
SELinux has 2 policies
1. Targeted = default policy that implements access control for targeted process. Each process is run in a confined domain to dramatically limit process access to files
2. MLS(multi-level security)
and 3 modes
1. Enforcing = default mode and enforces the loaded security policy across the system
2. Permissive = system logs all activity but does not deny activity
3. Disabled = when SELinux is disabled on a system VS

AppArmor has 2 types of rules
1. Paths = determines which files an app or process can access
2. Capabilities = specify the privilege that a confined process can use
and 2 modes
1. Enforce = policy is enforced
2. Complain = policy violations are only logged