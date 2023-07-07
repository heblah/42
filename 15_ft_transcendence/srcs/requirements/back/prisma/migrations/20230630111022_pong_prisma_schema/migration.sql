/*
  Warnings:

  - You are about to drop the column `blockedChannelUserId` on the `block` table. All the data in the column will be lost.
  - You are about to drop the column `blockerChannelUserId` on the `block` table. All the data in the column will be lost.

*/
-- DropForeignKey
ALTER TABLE "block" DROP CONSTRAINT "block_blockedChannelUserId_fkey";

-- DropForeignKey
ALTER TABLE "block" DROP CONSTRAINT "block_blockerChannelUserId_fkey";

-- AlterTable
ALTER TABLE "block" DROP COLUMN "blockedChannelUserId",
DROP COLUMN "blockerChannelUserId",
ALTER COLUMN "blockedUserId" SET DEFAULT -1,
ALTER COLUMN "blockerUserId" SET DEFAULT -1;

-- AddForeignKey
ALTER TABLE "block" ADD CONSTRAINT "block_blockerUserId_fkey" FOREIGN KEY ("blockerUserId") REFERENCES "User"("id") ON DELETE RESTRICT ON UPDATE CASCADE;

-- AddForeignKey
ALTER TABLE "block" ADD CONSTRAINT "block_blockedUserId_fkey" FOREIGN KEY ("blockedUserId") REFERENCES "User"("id") ON DELETE RESTRICT ON UPDATE CASCADE;
